cmake_minimum_required(VERSION 3.26)
project(CP_temps)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)

add_executable(CP_temps
        main.cpp
        DS/SegmantTree.cpp
        DS/OrderdSet.cpp
        DS/Lazy_propagation.cpp
        DS/DSU.cpp
        other/Pragmas.cpp)
