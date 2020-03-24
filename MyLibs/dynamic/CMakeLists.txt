cmake_minimum_required(VERSION 3.10)
PROJECT(dynamic)

set(CMAKE_CXX_FLAGS "-pthread -fprofile-arcs -ftest-coverage")
add_library(dynamic SHARED parallel_find_sum.cpp ../find_sum.h)
target_include_directories(dynamic PRIVATE ../)
