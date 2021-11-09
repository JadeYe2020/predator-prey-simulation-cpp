cmake_minimum_required(VERSION 3.20)
project(PolyVehicles)

set(CMAKE_CXX_STANDARD 14)

add_executable(PolyVehicles main.cpp Vehicle.cpp Vehicle.h Boat.cpp Boat.h Bicycle.cpp Bicycle.h)
