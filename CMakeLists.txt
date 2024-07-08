cmake_minimum_required(VERSION 3.16)

project(Exception VERSION "1.0.0")

set(CMAKE_CXX_STANDARD 17)
set(PROJECT_DIR ${CMAKE_CURRENT_SOURCE_DIR})

# build options
option(BUILD_EXAMPLES_SRC "Build examples source files" ON)

#enable_testing()

add_subdirectory(general)

if (BUILD_EXAMPLES_SRC)
    add_subdirectory(examples)
endif()