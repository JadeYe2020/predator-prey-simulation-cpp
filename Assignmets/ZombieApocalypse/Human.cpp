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
    if( x>0 && city->getOrganism(x-1, y) == NULL ) {
        //put the human to the new position
        city->setOrganism(this, x-1, y);
        //put an empty space to the previous position;
        city->setOrganism(NULL, x, y);
        //update the human's new position args
        x -= 1;
    }
}

char Human::getSpecies(){
    return species;
}

//void Human::getPosition() {
//
//}