//
// Created by JadeYe on 11/28/2021.
//

#include <iostream>
#include <vector>
#include <algorithm>
#include <random>
#include <chrono>
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
    if(!moved)
    {
        vector<direction> emptySp;
        if(x == 0) {
            if(city->getOrganism(x+1, y) == NULL)
                emptySp.push_back(EAST);
        }
        else if(x == GRIDSIZE-1) {
            if(city->getOrganism(x+-1, y) == NULL)
                emptySp.push_back(WEST);
        }
        else {
            if(city->getOrganism(x+1, y) == NULL)
                emptySp.push_back(EAST);
            if(city->getOrganism(x+-1, y) == NULL)
                emptySp.push_back(WEST);
        }

        if(y == 0) {
            if(city->getOrganism(x, y+1) == NULL)
                emptySp.push_back(SOUTH);
        }
        else if(y == GRIDSIZE-1) {
            if(city->getOrganism(x, y+-1) == NULL)
                emptySp.push_back(NORTH);
        }
        else {
            if(city->getOrganism(x, y+1) == NULL)
                emptySp.push_back(SOUTH);
            if(city->getOrganism(x, y+-1) == NULL)
                emptySp.push_back(NORTH);
        }

        if(emptySp.size() > 0)
        {
            //shuffle vector
            unsigned seed = chrono::system_clock::now().time_since_epoch().count();//create random seed using system clock
            shuffle(emptySp.begin(), emptySp.end(), default_random_engine(seed));

            switch (emptySp[0]) {
                case EAST:
                    //put the human to the new position
                    city->setOrganism(this, x+1, y);
                    //put an empty space to the previous position;
                    city->setOrganism(NULL, x, y);
                    //update the human's properties
                    x += 1;
                    break;
                case WEST:
                    //put the human to the new position
                    city->setOrganism(this, x-1, y);
                    //put an empty space to the previous position;
                    city->setOrganism(NULL, x, y);
                    //update the human's properties
                    x -= 1;
                    break;
                case SOUTH:
                    //put the human to the new position
                    city->setOrganism(this, x, y+1);
                    //put an empty space to the previous position;
                    city->setOrganism(NULL, x, y);
                    //update the human's properties
                    y += 1;
                    break;
                case NORTH:
                    //put the human to the new position
                    city->setOrganism(this, x, y-1);
                    //put an empty space to the previous position;
                    city->setOrganism(NULL, x, y);
                    //update the human's properties
                    y -= 1;
                    break;
            }
        }
    } //end of if(!moved)
    //change the moved status
    moved = true;
}

char Human::getSpecies(){
    return species;
}

//void Human::getPosition() {
//
//}