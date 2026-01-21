cmake_minimum_required(VERSION 3.31.6)
project(Sprocket)

set(CMAKE_CXX_STANDARD 26)

add_executable(Sprocket main.cpp
        src/SampleGenerator.cpp
        include/SampleGenerator.h
        src/Math.cpp
        include/Math.h
)
