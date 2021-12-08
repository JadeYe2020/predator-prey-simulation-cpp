//
// Created by JadeYe on 11/28/2021.
//
#include <iostream>
#include <windows.h>
#include "GameSpecs.h"
#include "City.h"
using namespace std;

class City;

void Col(int c) //method to change the color of the "pen"
{
    HANDLE  hConsole;
    hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(hConsole, c);
}

Organism::Organism() {}

Organism::Organism( City *city )
{
    x = 0;
    y = 0;
    moved = false;
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
    //set the moved flag to true
    moved = true;
}

void Organism::waitForTurn()
{
    //reset moved value to false
    moved = false;
}

ostream& operator<<( ostream &output, Organism *organism )
{
    if(!organism) //if it's a nullptr, then print a "space"
    {
        Col(DEFAULT_COLOR);
        output << ' ' << SPACE_CH << ' ';
    }
    else //otherwise print the organism's character with the right color
    {
        switch (organism->species) {
            case HUMAN_CH:
                Col(HUMAN_COLOR);
                output << ' ' << HUMAN_CH << ' ';
                break;
            case ZOMBIE_CH:
                Col(ZOMBIE_COLOR);
                output << ' ' << ZOMBIE_CH << ' ';
                break;
        }
    }
    //reset the color to the default
    Col(DEFAULT_COLOR);

    return output;
}