cmake_minimum_required(VERSION 3.9)
project(algorithms)

set(CMAKE_CXX_STANDARD 17)

add_library(algorithms src/bits.hpp)
add_executable(tests tests/testsMain.cpp tests/testsBits.cpp tests/testsBits.hpp)