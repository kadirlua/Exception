set(LIBRARY_NAME BaseException)
set(PROJECT_GENERAL_DIR ${PROJECT_DIR}/general)

set(PROJECT_GENERAL_SOURCES
	${PROJECT_GENERAL_DIR}/BaseException.cpp
	${PROJECT_GENERAL_DIR}/SocketException.cpp
)

# build options
option(BUILD_SHARED_LIBS "Build using shared libraries" ON)

if (BUILD_SHARED_LIBS)
	add_library(${LIBRARY_NAME} SHARED ${PROJECT_GENERAL_SOURCES})
	if (WIN32)
		add_compile_definitions(EXCEPTION_COMPILE_DLL=1)
		target_compile_definitions(${LIBRARY_NAME} PRIVATE "EXCEPTION_DLL_EXPORT")
	endif()
else()
	add_library(${LIBRARY_NAME} STATIC ${PROJECT_GENERAL_SOURCES})
endif()

if (MSVC)
    target_compile_options(${LIBRARY_NAME} PRIVATE "/Zc:__cplusplus")
endif()

# Set the library version properties
set_target_properties(${LIBRARY_NAME} PROPERTIES
    VERSION ${PROJECT_VERSION}
    SOVERSION 1
)

# configure header template
configure_file(
    "${PROJECT_SOURCE_DIR}/general/version.h.in"
    "${PROJECT_BINARY_DIR}/general/version.h"
)

# Custom target to copy the CHANGELOG.md file to the build directory
add_custom_target(copy_changelog ALL
    COMMAND ${CMAKE_COMMAND} -E copy ${PROJECT_SOURCE_DIR}/CHANGELOG.md ${CMAKE_BINARY_DIR}/CHANGELOG.md
    DEPENDS ${PROJECT_SOURCE_DIR}/CHANGELOG.md
    COMMENT "Copying CHANGELOG.md to the build directory"
)

include(CPack)

# Set packaging details
set(CPACK_PACKAGE_NAME "Exception")
set(CPACK_PACKAGE_VERSION ${PROJECT_VERSION})
set(CPACK_PACKAGE_DESCRIPTION "Basic exception class implementations in modern C++")
set(CPACK_PACKAGE_MAINTAINER "kadirlua")

# Use file(GLOB ...) to match specific header files
file(GLOB HEADER_FILES "${PROJECT_SOURCE_DIR}/general/*.h")

# Install the matched header files
install(FILES ${HEADER_FILES} DESTINATION include)

install(FILES ${PROJECT_BINARY_DIR}/general/version.h DESTINATION include)

# Include the CHANGELOG.md and LICENSE files in the package
install(FILES ${PROJECT_SOURCE_DIR}/CHANGELOG.md DESTINATION .)
install(FILES ${PROJECT_SOURCE_DIR}/LICENSE DESTINATION .)

# Include other necessary files and targets
install(TARGETS ${LIBRARY_NAME}
    EXPORT ExceptionTargets
    RUNTIME DESTINATION bin
    LIBRARY DESTINATION lib
    ARCHIVE DESTINATION lib
    INCLUDES DESTINATION include
)

# Export the targets for other projects to find
install(EXPORT ExceptionTargets
        FILE ExceptionTargets.cmake
        NAMESPACE Exception::
        DESTINATION lib/cmake/Exception)

# Create a config file for find_package
include(CMakePackageConfigHelpers)
write_basic_package_version_file(
  "${CMAKE_CURRENT_BINARY_DIR}/ExceptionConfigVersion.cmake"
  VERSION ${PROJECT_VERSION}
  COMPATIBILITY AnyNewerVersion
)

configure_package_config_file(${PROJECT_SOURCE_DIR}/Config.cmake.in
  "${CMAKE_CURRENT_BINARY_DIR}/ExceptionConfig.cmake"
  INSTALL_DESTINATION lib/cmake/Exception
)

install(FILES
  "${CMAKE_CURRENT_BINARY_DIR}/ExceptionConfig.cmake"
  "${CMAKE_CURRENT_BINARY_DIR}/ExceptionConfigVersion.cmake"
  DESTINATION lib/cmake/Exception
)
