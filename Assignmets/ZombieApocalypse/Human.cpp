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
    recruitCount = 0;
}

Human::Human( City *city )
{
    species = HUMAN_CH;
    recruitCount = 0;
    this->city = city;
}

Human::~Human()
{
    if(city != NULL) //non-null test
        delete []city;
    city = NULL; //assign null
}

Human::direction Human::getNextStep() {

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

    if(emptySp.size() > 0) {
        //shuffle vector
        unsigned seed = chrono::system_clock::now().time_since_epoch().count();
        shuffle(emptySp.begin(), emptySp.end(), default_random_engine(seed));
        return emptySp[0];
    }
    else
        return STAY;
}

void Human::recruit() {
    direction next = this->getNextStep();

    if(next != STAY) {
        //create a new human
        Human *newH = new Human(city);
        newH->endTurn(); //set the moved value to true so that it cannot move this time

        switch (next) {
            case EAST:
                //put a new human to the east side
                city->setOrganism(newH, x+1, y);
                //update its properties
                newH->x = x+1;
                newH->y = y;
                break;
            case WEST:
                //put a new human to the west side
                city->setOrganism(newH, x-1, y);
                newH->x = x-1;
                newH->y = y;
                break;
            case SOUTH:
                //put a new human to the south side
                city->setOrganism(newH, x, y+1);
                newH->x = x;
                newH->y = y+1;
                break;
            case NORTH:
                //put a new human to the north side
                city->setOrganism(newH, x, y-1);
                newH->x = x;
                newH->y = y-1;
                break;
        } //end switch
    } //end if(!= STAY)

    //no matter recruit successful or not, reset step counter to zero
    this->recruitCount = 0;
}

void Human::move()
{
    if(!moved)
    {
        //increment step counter
        this->recruitCount ++;

        direction next = this->getNextStep();

        switch (next) {
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
            case STAY:
                break;
        } //end switch

        if(this->recruitCount == 3)
            this->recruit();
    } //end of if(!moved)
}

char Human::getSpecies(){
    return species;
}

//void Human::getPosition() {
//
//}