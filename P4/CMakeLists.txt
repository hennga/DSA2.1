cmake_minimum_required(VERSION 3.7)
project(P4_ADS)

set(CMAKE_CXX_STANDARD 11)

set(SOURCE_FILES P4_main.cpp P4_graph.cpp P4_graph.h P4_graphnode.cpp P4_graphnode.h)
add_executable(P4_ADS ${SOURCE_FILES})