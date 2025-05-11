cmake_minimum_required(VERSION 3.29)
project(complier C)

set(CMAKE_C_STANDARD 11)

add_executable(complier main.c
        headers/states_and_tokens.h
        headers/input_symbol.h)
