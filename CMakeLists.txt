cmake_minimum_required(VERSION 3.21)
project(kktoken-client)

set(CMAKE_CXX_STANDARD 20)

set(CMAKE_MODULE_PATH              "${CMAKE_SOURCE_DIR}/cmake")
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}")
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}")
set(CMAKE_EXPORT_COMPILE_COMMANDS  ON)

include(cmake/BuildFlags.cmake)
include(cmake/TestSolution.cmake)
include_directories(contrib/catch)

find_package(Catch REQUIRED)

add_executable(core core/core.cpp)

add_catch(test1 tests/test1.cpp)