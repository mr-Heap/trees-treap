cmake_minimum_required(VERSION 3.23)
project(trees_treap)

set(CMAKE_CXX_STANDARD 20)

add_executable(trees_treap include/RandomGenerator.h include/Treap.h src/RandomGenerator.cpp src/Treap.cpp src/main.cpp)
