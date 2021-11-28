cmake_minimum_required(VERSION 3.20)
project(ZombieApocalypse)

set(CMAKE_CXX_STANDARD 14)

add_executable(ZombieApocalypse main.cpp GameSpecs.h City.h Organism.h Human.h Zombie.h City.cpp)
