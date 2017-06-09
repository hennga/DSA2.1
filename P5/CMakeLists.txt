cmake_minimum_required(VERSION 3.7)
project(P5)

set(CMAKE_CXX_STANDARD 11)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -I/usr/X11R6/include -L/usr/X11R6/lib -lX11")


set(SOURCE_FILES main.cpp CImg.h Kompression.h IOSystem.h Huffman_IO.h)
add_executable(P5 ${SOURCE_FILES})


