cmake_minimum_required(VERSION 3.12)
project(gmp)

set(CMAKE_CXX_STANDARD 98)

add_executable(gmp
        mini-gmp.c
        mini-gmp.h
        CGMPBigInt.h
        CGMPBigInt.cpp
        main.cpp)