//
// Created by JadeYe on 11/28/2021.
//

#include <iostream>
#include <vector>
#include <algorithm>
#include <random>
#include <chrono>
#include "GameSpecs.h"
#include "City.h"
#include "Organism.h"
#include "Human.h"
#include "Zombie.h"
using namespace std;

class City;

Human::Human()
{
    species = HUMAN_CH;
}

Human::Human( City *city )
{
    species = HUMAN_CH;
    this->city = city;
}

Human::~Human()
{
    if(city != NULL) //non-null test
        delete []city;
    city = NULL; //assign null
}

void Human::move()
{
    if(!moved)
    {
        if( x>0 && city->getOrganism(x+WEST, y) == NULL ) {
            //put the human to the new position
            city->setOrganism(this, x+WEST, y);
            //put an empty space to the previous position;
            city->setOrganism(NULL, x, y);
            //update the human's properties
            x += WEST;
        }
        else if(y < GRIDSIZE && city->getOrganism(x, y+SOUTH) == NULL) {
            city->setOrganism(this, x, y+SOUTH);
            city->setOrganism(NULL, x, y);
            y = y+SOUTH;
        }
//        vector<Organism*> emptySp;
//        if(x == 0 && y == 0) {
//
//        }
        moved = true;
    }
}

char Human::getSpecies(){
    return species;
}

//void Human::getPosition() {
//
//}