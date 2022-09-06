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
        bool moved;
        City *city;
        char species;

    public:
        Organism();
        Organism( City *city);
        virtual ~Organism();

        virtual void move() = 0;
        virtual char getSpecies() = 0;

        void setPosition( int x, int y );
        void endTurn(); //to set moved value to true
        void waitForTurn(); //to set moved value to false

        friend ostream& operator<<( ostream &output, Organism *organism );
};

#endif //ZOMBIEAPOCALYPSE_ORGANISM_H
