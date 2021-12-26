cmake_minimum_required(VERSION 3.20)
project(lo21-projet-splendor-a21)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)

add_executable(lo21-projet-splendor-a21
        main.cpp
        splendor.h
        splendor.cpp
        materiel.cpp
        materiel.h
        ostream.cpp
        json.hpp)
