cmake_minimum_required(VERSION 3.7)
project(AdsPraktikum2_3129944)

set(CMAKE_CXX_STANDARD 14)

set(SOURCE_FILES main.cpp Ringpuffer.cpp Ringpuffer.h RingNode.cpp RingNode.h Menue.cpp Menue.h)
add_executable(AdsPraktikum2_3129944 ${SOURCE_FILES})