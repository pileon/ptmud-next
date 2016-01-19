cmake_minimum_required(VERSION 3.3)
project(ptmud-next
        LANGUAGES C
        VERSION 0.0.1)

set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -std=c11")

# configure_file(src/conf.h.in conf.h)

add_subdirectory(src)
