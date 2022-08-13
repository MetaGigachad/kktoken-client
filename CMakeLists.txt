cmake_minimum_required(VERSION 3.23.3)

project("KKToken Client"
  VERSION 0.1
  DESCRIPTION "Client for nodes of KKToken blockchain network."
  LANGUAGES CXX)

# Compiler config
set(CMAKE_CXX_STANDARD 20)
add_compile_options(
       -Wall -Werror -Wno-error=maybe-uninitialized
       $<$<CONFIG:RELEASE>:-Ofast>
       $<$<CONFIG:DEBUG>:-O0>
       $<$<CONFIG:DEBUG>:-ggdb3>
)

# Variables setup
set(CLIENT_SOURCE_DIR "${PROJECT_SOURCE_DIR}/src")
file(GLOB_RECURSE CLIENT_SOURCES "${CLIENT_SOURCE_DIR}/*.cpp" "${CLIENT_SOURCE_DIR}/*.h")
message(${CLIENT_SOURCES})

# Boost setup
find_package(Boost REQUIRED COMPONENTS system coroutine serialization)

# Client executable
add_executable(client ${CLIENT_SOURCES})
target_include_directories(client PRIVATE ${CLIENT_SOURCE_DIR} ${Boost_INCLUDE_DIRS})
target_link_libraries(client ${Boost_LIBRARIES})
