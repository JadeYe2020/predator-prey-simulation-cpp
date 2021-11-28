// Reference: assignment supporting docs
// Created by JadeYe on 11/28/2021.
//

#ifndef ZOMBIEAPOCALYPSE_CITY_H
#define ZOMBIEAPOCALYPSE_CITY_H

#include <iostream>
#include "GameSpecs.h"

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

    friend ostream& operator<<( ostream &output, World &world );

};

#endif //ZOMBIEAPOCALYPSE_CITY_H
