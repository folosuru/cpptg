cmake_minimum_required(VERSION 3.27)
project(cpptg)

set(CMAKE_CXX_STANDARD 20)
file(GLOB_RECURSE sources
        src/*.cpp
        src/*.hpp
)
add_executable(cpptg ${sources})
target_include_directories(cpptg PRIVATE lib)
