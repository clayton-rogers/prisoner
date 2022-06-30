cmake_minimum_required(VERSION 3.8)

project(prisoner)

add_compile_options(-Wall -Wextra -Wpedantic -Wconversion -Wunused -Wcast-qual -Wcast-align=strict -Wduplicated-branches -Wduplicated-cond -Wnull-dereference -Wswitch-enum -Wno-psabi)

set (CMAKE_CXX_STANDARD 20)

add_executable(${PROJECT_NAME} main.cpp)
