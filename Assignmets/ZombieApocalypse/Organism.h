// Reference: assignment supporting docs
// Created by JadeYe on 11/28/2021.
//

#ifndef ZOMBIEAPOCALYPSE_ORGANISM_H
#define ZOMBIEAPOCALYPSE_ORGANISM_H

#include <iostream>

using namespace std;

class City;

class Organism
{
    protected:
        int x;
        int y;
//        int width;
//        int height;
        bool moved;
        City *city;
        char species;

        enum { WEST, NORTH, EAST, SOUTH, NUM_DIRECTIONS };

    public:
        Organism();
//        Organism( City *city, int width, int height );
        Organism( City *city);
        virtual ~Organism();

        virtual void move() = 0;
        //virtual void spawn() = 0;
        virtual char getSpecies() = 0; //this could also be coded concrete here
//        virtual void getPosition() = 0;

        void setPosition( int x, int y );
        void endTurn();
//        bool isTurn(); ????

        friend ostream& operator<<( ostream &output, Organism *organism );
};

#endif //ZOMBIEAPOCALYPSE_ORGANISM_H
