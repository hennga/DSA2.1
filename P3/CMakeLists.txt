cmake_minimum_required(VERSION 3.7)
project(ADS_P3_CLION)

set(CMAKE_CXX_STANDARD 11)

set(CMAKE_BUILD_TYPE Release)
set(SOURCE_FILES main.cpp MyAlgo.cpp MyAlgo.h)
add_definitions(-fopenmp -lgomp)
add_executable(ADS_P3_CLION ${SOURCE_FILES})

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11 -fopenmp -O3")

find_package(OpenMP)
if (OPENMP_FOUND)
    set (CMAKE_C_FLAGS "${CMAKE_C_FLAGS} ${OpenMP_C_FLAGS}")
    set (CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} ${OpenMP_CXX_FLAGS}")
endif()
