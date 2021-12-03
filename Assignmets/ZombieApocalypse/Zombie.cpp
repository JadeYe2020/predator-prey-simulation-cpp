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

Zombie::Zombie()
{
    species = ZOMBIE_CH;
}

Zombie::Zombie( City *city )
{
    species = ZOMBIE_CH;
    this->city = city;
}

Zombie::~Zombie()
{
    if(city != NULL) //non-null test
        delete []city;
    city = NULL; //assign null
}

void Zombie::move()
{

}

char Zombie::getSpecies()
{
    return species;
}