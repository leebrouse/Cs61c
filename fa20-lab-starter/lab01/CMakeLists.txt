cmake_minimum_required(VERSION 3.27)
project(lab01 C)

set(CMAKE_C_STANDARD 11)

include_directories(.)

add_executable(lab01
        eccentric.c
        hello.c
        interactive_hello.c
        ll_cycle.c
        ll_cycle.h
        no_segfault_ex.c
        segfault_ex.c
        test_ll_cycle.c
        ll_cycle.c
        ll_cycle.c
        segfault_ex.c)
