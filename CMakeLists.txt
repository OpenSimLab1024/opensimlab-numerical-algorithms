cmake_minimum_required(VERSION 3.16)

project(numerical_algorithms
    VERSION 0.1.0
    LANGUAGES CXX
)

# Use modern C++
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

# Library target
add_library(opensimlab_numerical_algorithms
    src/solvers/root_finding/newton.cpp
)

# Public include directory
target_include_directories(opensimlab_numerical_algorithms
    PUBLIC
        ${CMAKE_CURRENT_SOURCE_DIR}/include
)

# Warnings (optional but recommended)
if (MSVC)
    target_compile_options(opensimlab_numerical_algorithms PRIVATE /W4)
else()
    target_compile_options(opensimlab_numerical_algorithms PRIVATE -Wall -Wextra -Wpedantic)
endif()

