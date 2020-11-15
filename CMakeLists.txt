# cmake_minimum_required(VERSION <specify CMake version here>)
project(tp2_mock)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -lwiringPi")
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11 -pthread")

add_executable(tp2_mock main.cpp cpp_file/InputPin.cpp h_file/InputPin.h cpp_file/OutputPin.cpp h_file/OutputPin.h cpp_file/Lock.cpp h_file/Lock.h cpp_file/InputCallBack.cpp h_file/InputCallBack.h)