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