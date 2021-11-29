//
// Created by JadeYe on 11/28/2021.
//
#include <iostream>
#include "Organism.h"
using namespace std;

class City;

Organism::Organism():x(0), y(0), moved(false) {
    city = NULL;
    species = NULL;
}

Organism::Organism( City *city):x(0), y(0), moved(false)
{
    this->city = city;
    species = NULL;
}

Organism::~Organism(){}

void Organism::setPosition( int x, int y )
{
    this->x = x;
    this->y = y;
}
void Organism::endTurn()
{
    moved = true;
}

ostream& operator<<( ostream &output, Organism *organism )
{
    output << "-";
    return output;
}