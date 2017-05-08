cmake_minimum_required(VERSION 3.7)
project(Praktikum2Tree)

set(CMAKE_CXX_STANDARD 14)

set(SOURCE_FILES main.cpp Tree.cpp Tree.h TreeNode.cpp TreeNode.h Menue.cpp Menue.h DataEntry.cpp DataEntry.h Datareader.cpp Datareader.h)
add_executable(Praktikum2Tree ${SOURCE_FILES})