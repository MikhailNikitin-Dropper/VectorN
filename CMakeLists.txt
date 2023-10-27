cmake_minimum_required(VERSION 3.26)
project(VectorN)

set(CMAKE_CXX_STANDARD 17)

add_executable(VectorN main.cpp
        Vector.cpp
        Vector.h
        VectorTest.cpp
        VectorTest.h)
