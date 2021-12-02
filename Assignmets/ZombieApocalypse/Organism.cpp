//
// Created by JadeYe on 11/28/2021.
//
#include <iostream>
#include <windows.h>
#include "GameSpecs.h"
#include "City.h"
#include "Organism.h"
#include "Human.h"
#include "Zombie.h"
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

Organism::Organism( City *city ):x(0), y(0), moved(false)
{
    this->city = city;
    species = '\0';
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
    if(!organism)
    {
        Col(DEFAULT_COLOR);
        output << char(SPACE_CH);
    }
    else
    {
        switch (organism->species) {
            case HUMAN_CH:
                Col(HUMAN_COLOR);
                output << HUMAN_CH;
                break;
            case ZOMBIE_CH:
                Col(ZOMBIE_COLOR);
                output << ZOMBIE_CH;
                break;
//            default:
//                Col(DEFAULT_COLOR);
//                output << char(SPACE_CH);
//                break;
        }
    }

    return output;
}