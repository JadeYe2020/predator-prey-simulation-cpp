// Reference: assignment supporting docs
// Created by JadeYe on 11/28/2021.
//

#ifndef ZOMBIEAPOCALYPSE_HUMAN_H
#define ZOMBIEAPOCALYPSE_HUMAN_H

#include "Organism.h"

class Human : public Organism
{
    public:
        enum direction { WEST, NORTH, EAST, SOUTH };

        Human();
        Human( City *city );
        virtual ~Human();

        void move();
        char getSpecies();
//        void getPosition()
};

#endif //ZOMBIEAPOCALYPSE_HUMAN_H
