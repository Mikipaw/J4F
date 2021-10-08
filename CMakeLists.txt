cmake_minimum_required(VERSION 3.16)
project(J4F)

set(CMAKE_CXX_STANDARD 20)

add_executable(J4F main.cpp matrix.cpp ReversedPolishCalculator.cpp)