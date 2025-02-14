cmake_minimum_required(VERSION 3.30)
project(cop3503c)

set(CMAKE_CXX_STANDARD 20)

add_executable(cop3503c Lab1/lab1.cpp
        Lab2/Vehicle.cpp
        Lab2/Vehicle.h
        Lab2/lab2_main.cpp
        Lab2/Showroom.cpp
        Lab2/Showroom.h
        Lab2/Dealership.cpp
        Lab2/Dealership.h
        Lab3/ContactBook.cpp
        Lab3/ContactBook.h
        Lab3/lab3_main.cpp
)
