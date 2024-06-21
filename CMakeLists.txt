cmake_minimum_required(VERSION 3.16)

project(Exception VERSION "1.0.0")

set(CMAKE_CXX_STANDARD 14)
set(PROJECT_DIR ${CMAKE_CURRENT_SOURCE_DIR})

#enable_testing()

add_subdirectory(general)
add_subdirectory(examples)