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
    species = 'H';
}

Human::Human( City *city )
{
    species = 'H';
}

Human::~Human()
{
    if(city != NULL) //non-null test
        delete []city;
    city = NULL; //assign null
}

void Human::move()
{
    x -= 1;
    y -= 1;
}

char Human::getSpecies(){
    return species;
}