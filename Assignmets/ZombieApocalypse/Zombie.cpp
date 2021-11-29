//
// Created by JadeYe on 11/28/2021.
//

#include <iostream>
#include "Organism.h"
#include "Zombie.h"
using namespace std;

class City;

Zombie::Zombie()
{
    species = 'Z';
}

Zombie::Zombie( City *city )
{
    species = 'Z';
}

Zombie::~Zombie()
{
    if(city != NULL) //non-null test
        delete []city;
    city = NULL; //assign null
}

void Zombie::move()
{
    x += 1;
    y += 1;
}

char Zombie::getSpecies()
{
    return species;
}