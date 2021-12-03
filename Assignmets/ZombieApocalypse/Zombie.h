// Reference: assignment supporting docs
// Created by JadeYe on 11/28/2021.
//

#ifndef ZOMBIEAPOCALYPSE_ZOMBIE_H
#define ZOMBIEAPOCALYPSE_ZOMBIE_H

#include "Organism.h"

class Zombie : public Organism
{
    public:
        enum direction { WEST, NORTH, EAST, SOUTH, NW, NE, SW, SE };

        Zombie();
        Zombie( City *city );
        virtual ~Zombie();

        void move();
        char getSpecies();
//        void getPosition()
};

#endif //ZOMBIEAPOCALYPSE_ZOMBIE_H
