//
// Created by JadeYe on 11/28/2021.
//

#include <iostream>
#include "GameSpecs.h"
#include "City.h"
#include "Organism.h"

using namespace std;

class Organism;

City::City() {
    for(int i=0; i<GRIDSIZE; i++) {
        for(int j=0; j<GRIDSIZE; j++) {
            Organism or;
            grid[i][j] = or;
        }
    }
}

City::~City(){}

Organism City::*getOrganism( int x, int y )
{

}

void City::setOrganism( Organism *organism, int  x, int y )
{

}

void City::move()
{

}

ostream& operator<<( ostream &output, City &city ){

}