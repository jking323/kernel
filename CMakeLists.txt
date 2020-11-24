cmake_minimum_required(VERSION 3.10)
project(Kernel C)

set(CMAKE_C_STANDARD 90)

add_executable(Kernel kernel.c keyboard.c first.c)