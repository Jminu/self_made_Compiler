cmake_minimum_required(VERSION 3.29)
project(complier C)

set(CMAKE_C_STANDARD 11)

add_executable(complier main.c
        headers/LRparser/ACTIONtable.h
        headers/LRparser/GOTOtable.h
        src/LRparser/action_table.c
        src/LRparser/goto_table.c
        headers/LRparser/stack.h
        src/LRparser/stack.c
        headers/LRparser/parser.h
        src/LRparser/parser.c)
