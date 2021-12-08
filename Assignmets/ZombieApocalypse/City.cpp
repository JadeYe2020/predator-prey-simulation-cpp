//
// Created by JadeYe on 11/28/2021.
//

#include <iostream>
#include "GameSpecs.h"
#include "City.h"

using namespace std;

class Organism;
class Human;
class Zombie;

City::City()
{
    for(int i=0; i<GRIDSIZE; i++) {
        for(int j=0; j<GRIDSIZE; j++) {
            Organism *ogn = NULL;
            grid[i][j] = (Organism*) ogn;
        }
    }
}

City::~City()
{
    //source: https://stackoverflow.com/questions/30720594/deleting-a-dynamically-allocated-2d-array/30720628
    for(int i=0; i<GRIDSIZE; i++) {
        for(int j=0; j<GRIDSIZE; j++) {
            delete [] grid[i][j];
        }
        delete [] *grid[i];
    }
    delete [] **grid;
    **grid = NULL;
}

Organism* City::getOrganism( int x, int y )
{
    return grid[y][x];
}

void City::setOrganism( Organism *organism, int  x, int y )
{
    grid[y][x] = organism; //add an organism or a nullptr into the grid
    if(organism != NULL)
        organism->setPosition(x, y); //update the organism's properties accordingly
}

void City::move()
{
    for(int i=0; i<GRIDSIZE; i++) {
        for(int j=0; j<GRIDSIZE; j++) {
            if(grid[i][j] != NULL) {
                Organism *picked = grid[i][j];

                picked->move(); //the organism will do everything they can do
                picked->endTurn(); //flip the moved value to true
            }
        }
    }
}

void City::reset()
{
    for(int i=0; i<GRIDSIZE; i++) {
        for(int j=0; j<GRIDSIZE; j++) {
            if(grid[i][j] != NULL)
                //flip the moved value to false
                grid[i][j]->waitForTurn();
        }
    }
}

int City::countType(char species) {
    int count = 0;

    for(int i=0; i<GRIDSIZE; i++) {
        for(int j=0; j<GRIDSIZE; j++) {
            if(grid[i][j] != NULL) {
                if(grid[i][j]->getSpecies() == species)
                    count ++;
            }
        }
    }
    return count;
}

ostream& operator<<( ostream &output, City &city ){
    for(int i=0; i<GRIDSIZE; i++) {
        for(int j=0; j<GRIDSIZE; j++) {
            //use the << operator that's overloaded in Organism class to get the output
            output << city.grid[i][j];
        }
        output << "\n";
    }

    return output;
}