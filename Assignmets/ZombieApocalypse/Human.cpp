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

    if(x != 0) {
        if(city->getOrganism(x+1, y) == NULL)
            emptySp.push_back(EAST);
    }

    if(x != GRIDSIZE - 1) {
        if(city->getOrganism(x-1, y) == NULL)
            emptySp.push_back(WEST);
    }

    if(y != 0) {
        if(city->getOrganism(x, y-1) == NULL)
            emptySp.push_back(NORTH);
    }

    if(y != GRIDSIZE - 1) {
        if(city->getOrganism(x, y+1) == NULL)
            emptySp.push_back(SOUTH);
    }

//    switch (x) {
//        case 0: //when the human is at the west end of the city
//            switch(y) {
//                case 0: //when the human is at the north-west corner, check only east and south
//                    if(city->getOrganism(x+1, y) == NULL)
//                        emptySp.push_back(EAST);
//                    if(city->getOrganism(x, y+1) == NULL)
//                        emptySp.push_back(SOUTH);
//                    break;
//                case GRIDSIZE-1: //when the human is at the south-west corner, check only east and north
//                    if(city->getOrganism(x+1, y) == NULL)
//                        emptySp.push_back(EAST);
//                    if(city->getOrganism(x, y-1) == NULL)
//                        emptySp.push_back(NORTH);
//                    break;
//                default:
//                    //check east, north and south
//                    if(city->getOrganism(x+1, y) == NULL)
//                        emptySp.push_back(EAST);
//                    if(city->getOrganism(x, y-1) == NULL)
//                        emptySp.push_back(NORTH);
//                    if(city->getOrganism(x, y+1) == NULL)
//                        emptySp.push_back(SOUTH);
//                    break;
//            }
//            break;
//        case GRIDSIZE-1: //when the human is at the east end of the city
//            switch(y) {
//                case 0: //when the human is at the north-east corner, check only west and south
//                    if(city->getOrganism(x-1, y) == NULL)
//                        emptySp.push_back(WEST);
//                    if(city->getOrganism(x, y+1) == NULL)
//                        emptySp.push_back(SOUTH);
//                    break;
//                case GRIDSIZE-1: //when the human is at the south-east corner, check only west and north
//                    if(city->getOrganism(x-1, y) == NULL)
//                        emptySp.push_back(WEST);
//                    if(city->getOrganism(x, y-1) == NULL)
//                        emptySp.push_back(NORTH);
//                    break;
//                default: //check west, north and south
//                    if(city->getOrganism(x-1, y) == NULL)
//                        emptySp.push_back(WEST);
//                    if(city->getOrganism(x, y-1) == NULL)
//                        emptySp.push_back(NORTH);
//                    if(city->getOrganism(x, y+1) == NULL)
//                        emptySp.push_back(SOUTH);
//                    break;
//            }
//            break;
//        default:
//            switch(y) {
//                case 0: //when the human is at the north end of the city, check only east, west and south
//                    if(city->getOrganism(x+1, y) == NULL)
//                        emptySp.push_back(EAST);
//                    if(city->getOrganism(x-1, y) == NULL)
//                        emptySp.push_back(WEST);
//                    if(city->getOrganism(x, y+1) == NULL)
//                        emptySp.push_back(SOUTH);
//                    break;
//                case GRIDSIZE-1: //when at the south end of the city, check only east, west and north
//                    if(city->getOrganism(x+1, y) == NULL)
//                        emptySp.push_back(EAST);
//                    if(city->getOrganism(x-1, y) == NULL)
//                        emptySp.push_back(WEST);
//                    if(city->getOrganism(x, y-1) == NULL)
//                        emptySp.push_back(NORTH);
//                    break;
//                default: //check all 4 directions
//                    if(city->getOrganism(x+1, y) == NULL)
//                        emptySp.push_back(EAST);
//                    if(city->getOrganism(x-1, y) == NULL)
//                        emptySp.push_back(WEST);
//                    if(city->getOrganism(x, y-1) == NULL)
//                        emptySp.push_back(NORTH);
//                    if(city->getOrganism(x+1, y-1) == NULL)
//                    if(city->getOrganism(x, y+1) == NULL)
//                        emptySp.push_back(SOUTH);
//                    break;
//            }
//            break;
//    } // end switch

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

    //no matter recruit successful or not, reset step counter to zero
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
                //put the human to the new position
                city->setOrganism(this, x-1, y);
                //put an empty space to the previous position;
                city->setOrganism(NULL, x+1, y);
                break;
            case SOUTH:
                //put the human to the new position
                city->setOrganism(this, x, y+1);
                //put an empty space to the previous position;
                city->setOrganism(NULL, x, y-1);
                break;
            case NORTH:
                //put the human to the new position
                city->setOrganism(this, x, y-1);
                //put an empty space to the previous position;
                city->setOrganism(NULL, x, y+1);
                break;
            case STAY:
                break;
        } //end switch

        if(this->recruitClock == HUMAN_BREED)
            this->recruit();
    } //end of if(!moved)
}

char Human::getSpecies(){
    return species;
}

//void Human::getPosition() {
//
//}