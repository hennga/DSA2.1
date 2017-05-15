cmake_minimum_required(VERSION 3.7)
project(ADS_P3_CLION)

set(CMAKE_CXX_STANDARD 11)

set(SOURCE_FILES main.cpp MyAlgo.cpp MyAlgo.h)
#add_definitions(-fopenmp -lgomp)
add_executable(ADS_P3_CLION ${SOURCE_FILES})
