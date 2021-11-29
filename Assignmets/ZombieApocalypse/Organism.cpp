//
// Created by JadeYe on 11/28/2021.
//
#include <iostream>
#include <windows.h>
#include "GameSpecs.h"
#include "Organism.h"
using namespace std;

class City;

void Col(int c)
{
    HANDLE  hConsole;
    hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(hConsole, c);
}

Organism::Organism():x(0), y(0), moved(false) {
    city = NULL;
    species = '\0';
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
    switch (organism->species) {
        case 'H':
            Col(HUMAN_COLOR);
            output << "H";
            break;
        case 'Z':
            Col(ZOMBIE_COLOR);
            output << "Z";
            break;
        default:
            Col(DEFAULT_COLOR);
            output << "-";
            break;
    }

    return output;
}