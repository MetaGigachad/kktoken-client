cmake_minimum_required(VERSION 3.21)
project("kktoken-client")

set(CMAKE_CXX_STANDARD 20)

set(CMAKE_MODULE_PATH              "${CMAKE_SOURCE_DIR}/cmake")
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}")
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}")
set(CMAKE_EXPORT_COMPILE_COMMANDS  ON)

# Catch Library Setup
include(cmake/BuildFlags.cmake)
include(cmake/TestSolution.cmake)
include_directories(contrib/catch)
find_package(Catch REQUIRED)

# Main Executable
add_executable(run-client)
add_subdirectory(kktoken-client)

# Tests
get_target_property(CLIENT_SOURCES run-client SOURCES)
list(REMOVE_AT CLIENT_SOURCES 0)    # Removes "core.cpp" file from list to avoid 2 main functions

add_catch(tests-main ${CLIENT_SOURCES})
#add_subdirectory(tests)
