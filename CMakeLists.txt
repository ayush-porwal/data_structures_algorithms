cmake_minimum_required(VERSION 3.5.0)
project(data_structures_algorithms VERSION 0.1.0 LANGUAGES CXX)

# # Enable warnings
# set(CMAKE_CXX_WARNINGS true)
# set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -g -fexceptions")

add_executable(data_structures_algorithms main.cpp)
set_property(TARGET data_structures_algorithms PROPERTY CXX_STANDARD 20)

