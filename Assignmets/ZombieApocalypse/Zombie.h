// Reference: assignment supporting docs
// Created by JadeYe on 11/28/2021.
//

#ifndef ZOMBIEAPOCALYPSE_ZOMBIE_H
#define ZOMBIEAPOCALYPSE_ZOMBIE_H

#include "Organism.h"

class Zombie : public Organism
{
    private:
        int breedCount;
        int starveClock;

    public:
        enum direction { WEST, NORTH, EAST, SOUTH, NW, NE, SW, SE, STAY };

        Zombie();
        Zombie( City *city );
        virtual ~Zombie();

        direction getNextEat();
        direction getNextMove();

//        void breed();
//        void starve();

        void move();
//        void eat();

        char getSpecies();
//        void getPosition()
};

#endif //ZOMBIEAPOCALYPSE_ZOMBIE_H
