cmake_minimum_required(VERSION 3.8)
project(mp2_lab7_arithmetic)

set(CMAKE_CXX_STANDARD 11)

set(SOURCE_FILES main.cpp include/Stack.h src/Calculate.cpp include/Calculate.h include/List.h include/Node.h)
add_executable(mp2_lab7_arithmetic ${SOURCE_FILES})