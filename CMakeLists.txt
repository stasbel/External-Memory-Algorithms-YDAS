cmake_minimum_required(VERSION 3.12)
project(External_Memory_Algorithms_YDAS)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)
include_directories(ema_practice_1)

add_executable(External_Memory_Algorithms_YDAS
        ema_practice_1/ema_practice_1.pdf
        ema_practice_1/main.cpp
        ema_practice_1/Makefile
        LICENSE
        README.md)
