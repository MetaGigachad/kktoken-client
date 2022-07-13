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

add_subdirectory(tests)

# CORE EXECUTABLE ------------------------------------------------------------------------------------------------------

add_executable(core src/core/core.cpp

        src/data_structures/Transaction/Transaction.h src/data_structures/Transaction/Transaction.cpp
        src/data_structures/User/User.cpp src/data_structures/User/User.h
        src/data_structures/TokensAmount/TokensAmount.cpp src/data_structures/TokensAmount/TokensAmount.h
        src/data_structures/Signature/Signature.cpp src/data_structures/Signature/Signature.h

        src/config/constants.h src/config/constants.cpp tests/stun.cpp)

target_include_directories(core PUBLIC
        src
        src/core
        src/data_structures

        src/data_structures/User
        src/data_structures/Transaction
        src/data_structures/TokensAmount
        src/data_structures/Signature

        src/config)

# TESTS ----------------------------------------------------------------------------------------------------------------

add_catch(data_structures_tests tests/data_structures.cpp

        src/data_structures/TokensAmount/TokensAmount.cpp src/data_structures/TokensAmount/TokensAmount.h

        src/config/constants.h src/config/constants.cpp)

target_include_directories(data_structures_tests PUBLIC
        src
        src/core
        src/data_structures

        src/data_structures/User
        src/data_structures/Transaction
        src/data_structures/TokensAmount
        src/data_structures/Signature

        src/config)

add_catch(stun_tests tests/stun.cpp

        src/utils/stun.h)

target_include_directories(stun_tests PUBLIC
        src
        src/utils)
