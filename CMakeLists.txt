cmake_minimum_required(VERSION 3.20)
project(ZombieApocalypse)

set(CMAKE_CXX_STANDARD 14)

add_executable(ZombieApocalypse src/main.cpp src/GameSpecs.h src/City.h src/Organism.h src/Human.h src/Zombie.h src/City.cpp src/Organism.cpp src/Human.cpp src/Zombie.cpp)
