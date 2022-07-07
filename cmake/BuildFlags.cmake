message("C++ version: ${CMAKE_CXX_STANDARD}")

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Werror -g")

set(CMAKE_CXX_FLAGS_ASAN "-g -fsanitize=address,undefined -fno-sanitize-recover=all"
    CACHE STRING "Compiler flags in asan build"
    FORCE)

set(CMAKE_CXX_FLAGS_COVERAGE "${CMAKE_CXX_FLAGS_ASAN} -fprofile-instr-generate -fcoverage-mapping")
