// Reference: assignment supporting docs
// Created by JadeYe on 11/28/2021.
//

#ifndef ZOMBIEAPOCALYPSE_HUMAN_H
#define ZOMBIEAPOCALYPSE_HUMAN_H

#include "Organism.h"

class Human : public Organism
{
    private:
        int recruitClock;

    public:
        enum direction { WEST, NORTH, EAST, SOUTH, STAY };

        Human();
        Human( City *city );
        virtual ~Human();

        direction getNextStep();

        void recruit();

        void move();

        char getSpecies();
};

#endif //ZOMBIEAPOCALYPSE_HUMAN_H
