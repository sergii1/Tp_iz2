cmake_minimum_required(VERSION 3.10)
PROJECT(static)
add_library(static common_find_sum.cpp ../find_sum.h)
target_include_directories(static PRIVATE ../)
