cmake_minimum_required(VERSION 3.17)
project(Kernel C)

set(CMAKE_C_STANDARD 90)

add_executable(Kernel main.c kernel.c)