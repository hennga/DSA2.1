cmake_minimum_required(VERSION 3.7)
project(P4)

set(CMAKE_CXX_STANDARD 11)

set(SOURCE_FILES main.cpp P4_graph.cpp P4_graphnode.cpp)
add_executable(P4 ${SOURCE_FILES})