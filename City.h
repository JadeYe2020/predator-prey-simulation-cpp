// Reference: assignment supporting docs
// Created by JadeYe on 11/28/2021.
//

#ifndef ZOMBIEAPOCALYPSE_CITY_H
#define ZOMBIEAPOCALYPSE_CITY_H

#include <iostream>
#include "GameSpecs.h"
#include "City.h"
#include "Organism.h"
#include "Human.h"
#include "Zombie.h"

using namespace std;

class Organism;

class City
{
    protected:
        Organism *grid[GRIDSIZE][GRIDSIZE];

    public:
        City();
        virtual ~City();

        Organism *getOrganism( int x, int y );
        void setOrganism( Organism *organism, int x, int y );

        void move();
        void reset();
        int countType(char species);

        friend ostream& operator<<( ostream &output, City &city );
};

#endif //ZOMBIEAPOCALYPSE_CITY_H
