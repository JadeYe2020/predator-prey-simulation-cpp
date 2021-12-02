//
// Created by JadeYe on 11/28/2021.
//

#include <iostream>
#include "GameSpecs.h"
#include "City.h"
#include "Organism.h"
#include "Human.h"
#include "Zombie.h"

using namespace std;

class Organism;
class Human;
class Zombie;

City::City() {
    for(int i=0; i<GRIDSIZE; i++) {
        for(int j=0; j<GRIDSIZE; j++) {
//            Human *ogn = new Human;
            //a grid of null pointer
            Organism *ogn = NULL;
            grid[i][j] = (Organism*) ogn;
        }
    }
}

City::~City(){

    //source: https://stackoverflow.com/questions/30720594/deleting-a-dynamically-allocated-2d-array/30720628
    for(int i=0; i<GRIDSIZE; i++) {
        for(int j=0; j<GRIDSIZE; j++) {
            delete [] grid[i][j];
        }
        delete [] *grid[i];
    }
    delete [] **grid;
    **grid = NULL;

    cout << "{City's destructor fired}" << endl;
}

Organism* City::getOrganism( int x, int y )
{
    return grid[y][x];
}

void City::setOrganism( Organism *organism, int  x, int y )
{
    grid[y][x] = organism;
}

void City::move()
{
    for(int i=0; i<GRIDSIZE; i++) {
        for(int j=0; j<GRIDSIZE; j++) {
            if(grid[i][j] != NULL)
                grid[i][j]->move();
        }
    }
}

ostream& operator<<( ostream &output, City &city ){
    for(int i=0; i<GRIDSIZE; i++) {
        for(int j=0; j<GRIDSIZE; j++) {
            output << city.grid[i][j];
        }
        output << "\n";
    }

    return output;
}