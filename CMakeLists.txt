cmake_minimum_required(VERSION 3.16)

project(Exception)

set(CMAKE_CXX_STANDARD 14)
set(PROJECT_DIR ${CMAKE_SOURCE_DIR})
set(PROJECT_INCLUDE_DIR ${PROJECT_DIR})
set(PROJECT_GENERAL_DIR ${PROJECT_DIR}/general)
set(OPENSSL_VAL 0)

if (${OPENSSL_VAL})
find_package(OpenSSL REQUIRED)
endif()

set(PROJECT_SOURCES
        ${PROJECT_GENERAL_DIR}/BaseException.cpp
        ${PROJECT_GENERAL_DIR}/SocketException.cpp
        )

set(PROJECT_HEADERS
        ${PROJECT_INCLUDE_DIR}/general/BaseException.h
        ${PROJECT_INCLUDE_DIR}/general/SocketException.h
        )

include_directories(${PROJECT_INCLUDE_DIR}
${OPENSSL_INCLUDE_DIR}
)

add_executable(${PROJECT_NAME} ${PROJECT_SOURCES} "examples/exception.cpp")
target_link_libraries(${PROJECT_NAME} -lpthread)
if (${OPENSSL_VAL})
target_link_libraries(${PROJECT_NAME} OpenSSL::SSL)
endif()

if(WIN32)
  target_link_libraries(${PROJECT_NAME} Ws2_32 crypt32)
endif()