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

# Boost setup
set(Boost_USE_STATIC_LIBS OFF)
set(Boost_USE_MULTITHREADED ON)
set(Boost_USE_STATIC_RUNTIME OFF)
find_package(Boost REQUIRED COMPONENTS system coroutine serialization)

# Main Executable
add_executable(client)
add_subdirectory(kktoken-client)
target_include_directories(client PUBLIC kktoken-client ${Boost_INCLUDE_DIRS})
target_link_libraries(client ${Boost_LIBRARIES})
# Tests
get_target_property(CLIENT_SOURCES client SOURCES)
list(REMOVE_AT CLIENT_SOURCES 0)    # Removes "core.cpp" file from list to avoid 2 main functions

add_catch(tests-main ${CLIENT_SOURCES})
target_include_directories(tests-main PUBLIC kktoken-client)
#add_subdirectory("tests")

# Scratch targets
add_executable(scratch)
add_subdirectory("scratch-files")
target_include_directories(scratch PUBLIC ${Boost_INCLUDE_DIRS})
target_link_libraries(scratch ${Boost_LIBRARIES})
