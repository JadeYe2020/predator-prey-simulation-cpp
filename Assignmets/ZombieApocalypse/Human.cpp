//
// Created by JadeYe on 11/28/2021.
//

#include <vector>
#include <algorithm>
#include <random>
#include <chrono>
#include "GameSpecs.h"
#include "City.h"

using namespace std;

class City;

Human::Human() {}

Human::Human( City *city )
{
    species = HUMAN_CH;
    recruitClock = 0;
    this->city = city;
}

Human::~Human() {}

Human::direction Human::getNextStep() {
    //create a vector to store the available spaces
    vector<direction> emptySp;

    if(x != GRIDSIZE - 1) { //when the human is not at the east end, check east
        if(city->getOrganism(x+1, y) == NULL)
            emptySp.push_back(EAST);
    }

    if(x != 0) { //when the human is not at the west end, check west
        if(city->getOrganism(x-1, y) == NULL)
            emptySp.push_back(WEST);
    }

    if(y != 0) { //when the human is not at the north end, check north
        if(city->getOrganism(x, y-1) == NULL)
            emptySp.push_back(NORTH);
    }

    if(y != GRIDSIZE - 1) { //when the human is not at the south end, check south
        if(city->getOrganism(x, y+1) == NULL)
            emptySp.push_back(SOUTH);
    }

    if(emptySp.size() > 0) {
        //shuffle vector when it's not empty
        unsigned seed = chrono::system_clock::now().time_since_epoch().count();
        shuffle(emptySp.begin(), emptySp.end(), default_random_engine(seed));
        //get the first direction of the shuffled vector
        return emptySp[0];
    }
    else //otherwise return STAY
        return STAY;
}

void Human::recruit() {
    //randomly pick an available space
    direction next = this->getNextStep();

    if(next != STAY) { //recruit only when there's an available space
        //create a new human
        Human *newH = new Human(city);
        newH->endTurn(); //set the moved value to true so that it cannot move this time

        switch (next) {
            case EAST:
                //put a new human to the east side
                city->setOrganism(newH, x+1, y);
                break;
            case WEST:
                //put a new human to the west side
                city->setOrganism(newH, x-1, y);
                break;
            case SOUTH:
                //put a new human to the south side
                city->setOrganism(newH, x, y+1);
                break;
            case NORTH:
                //put a new human to the north side
                city->setOrganism(newH, x, y-1);
                break;
        } //end switch
    } //end if(!= STAY)

    //no matter recruit successful or not, reset the recruit clock to zero
    this->recruitClock = 0;
}

void Human::move()
{
    if(!moved)
    {
        //increment step counter
        this->recruitClock ++;

        direction next = this->getNextStep();

        switch (next) {
            case EAST:
                //put the human to the new position
                city->setOrganism(this, x+1, y);
                //put an empty space to the previous position;
                city->setOrganism(NULL, x-1, y);
                break;
            case WEST:
                city->setOrganism(this, x-1, y);
                city->setOrganism(NULL, x+1, y);
                break;
            case SOUTH:
                city->setOrganism(this, x, y+1);
                city->setOrganism(NULL, x, y-1);
                break;
            case NORTH:
                city->setOrganism(this, x, y-1);
                city->setOrganism(NULL, x, y+1);
                break;
            case STAY: //do nothing when there's no available space to move
                break;
        } //end switch

        //check whether the human reach the time when they can recruit
        if(this->recruitClock == HUMAN_BREED)
            this->recruit();
    } //end of if(!moved)
}

char Human::getSpecies(){
    return species;
}