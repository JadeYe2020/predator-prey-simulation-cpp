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
using namespace std;

class City;

Zombie::Zombie() {}

Zombie::Zombie( City *city )
{
    species = ZOMBIE_CH;
    this->city = city;
    breedCount = 0;
    starveClock = 0;
}

Zombie::~Zombie() {}

Zombie::direction Zombie::getNextEat() {
    //create a vector to store the available spaces
    vector<direction> spCanEat;
    //look for spaces with humans in
    if(x != GRIDSIZE - 1) { //when it is not at the east end, check east
        if(city->getOrganism(x+1, y) != NULL) { //check if there's an organism
            //check if the organism is human
            if(city->getOrganism(x+1, y)->getSpecies() == HUMAN_CH)
                spCanEat.push_back(EAST);
        }
    }

    if(x != 0) { //when it is not at the west end, check west
        if(city->getOrganism(x-1, y) != NULL) {
            if(city->getOrganism(x-1, y)->getSpecies() == HUMAN_CH)
                spCanEat.push_back(WEST);
        }
    }

    if(y != GRIDSIZE - 1) { //when it is not at the south end, check south
        if(city->getOrganism(x, y+1) != NULL) {
            if(city->getOrganism(x, y+1)->getSpecies() == HUMAN_CH)
                spCanEat.push_back(SOUTH);
        }
    }

    if(y != 0) { //when it is not at the north end, check north
        if(city->getOrganism(x, y-1) != NULL) {
            if(city->getOrganism(x, y-1)->getSpecies() == HUMAN_CH)
                spCanEat.push_back(NORTH);
        }
    }

    if(x != 0 && y != 0) { //when it is not at the north-west end, check north-west
        if(city->getOrganism(x-1, y-1) != NULL) {
            if(city->getOrganism(x-1, y-1)->getSpecies() == HUMAN_CH)
                spCanEat.push_back(NW);
        }
    }

    if(x != 0 && y != GRIDSIZE - 1) { //when it is not at the south-west end, check south-west
        if(city->getOrganism(x-1, y+1) != NULL) {
            if(city->getOrganism(x-1, y+1)->getSpecies() == HUMAN_CH)
                spCanEat.push_back(SW);
        }
    }

    if(x != GRIDSIZE - 1 && y != GRIDSIZE - 1) { //when it is not at the south-east end, check south-east
        if(city->getOrganism(x+1, y+1) != NULL) {
            if(city->getOrganism(x+1, y+1)->getSpecies() == HUMAN_CH)
                spCanEat.push_back(SE);
        }
    }

    if(x != GRIDSIZE - 1 && y != 0) { //when it is not at the north-east end, check north-east
        if(city->getOrganism(x+1, y-1) != NULL) {
            if(city->getOrganism(x+1, y-1)->getSpecies() == HUMAN_CH)
                spCanEat.push_back(NE);
        }
    }

    if(!spCanEat.empty()) {
        //shuffle vector when it's not empty
        unsigned seed = chrono::system_clock::now().time_since_epoch().count();
        shuffle(spCanEat.begin(), spCanEat.end(), default_random_engine(seed));
        //get the first direction of the shuffled vector
        return spCanEat[0];
    }
    else //otherwise return STAY
        return STAY;
}

Zombie::direction Zombie::getNextMove() {

    vector<direction> spCanMove;
    //look for empty spaces
    if(x != GRIDSIZE - 1) { //when it is not at the east end, check east
        if (city->getOrganism(x + 1, y) == NULL)
            spCanMove.push_back(EAST);
    }

    if(x != 0) { //when it is not at the west end, check west
        if (city->getOrganism(x - 1, y) == NULL)
            spCanMove.push_back(WEST);
    }

    if(y != GRIDSIZE - 1) { //when it is not at the south end, check south
        if (city->getOrganism(x, y + 1) == NULL)
            spCanMove.push_back(SOUTH);
    }

    if(y != 0) { //when it is not at the north end, check north
        if (city->getOrganism(x, y - 1) == NULL)
            spCanMove.push_back(NORTH);
    }

    if(x != 0 && y != 0) { //when it is not at the north-west end, check north-west
        if (city->getOrganism(x - 1, y - 1) == NULL)
            spCanMove.push_back(NW);
    }

    if(x != 0 && y != GRIDSIZE - 1) { //when it is not at the south-west end, check south-west
        if (city->getOrganism(x - 1, y + 1) == NULL)
            spCanMove.push_back(SW);
    }

    if(x != GRIDSIZE - 1 && y != GRIDSIZE - 1) { //when it is not at the south-east end, check south-east
        if (city->getOrganism(x + 1, y + 1) == NULL)
            spCanMove.push_back(SE);
    }

    if(x != GRIDSIZE - 1 && y != 0) { //when it is not at the north-east end, check north-east
        if (city->getOrganism(x + 1, y - 1) == NULL)
            spCanMove.push_back(NE);
    }

    if(!spCanMove.empty()) {
        //shuffle vector when it's not empty
        unsigned seed = chrono::system_clock::now().time_since_epoch().count();
        shuffle(spCanMove.begin(), spCanMove.end(), default_random_engine(seed));
        //get the first direction of the shuffled vector
        return spCanMove[0];
    }
    else
        return STAY;
}

void Zombie::move()
{
    if(!moved) {
        //increment breed counter
        this->breedCount ++;

        direction next = this->getNextEat();

        if(next == STAY) { //it has nothing to each
            //increment starve counter
            this->starveClock ++;

            if(starveClock == ZOMBIE_STARVE) { //too starved to be a zombie anymore
                //set a new Human on the same location
                Human *newH = new Human(city);
                newH->endTurn(); //set the moved value to true so that it cannot move this time
                city->setOrganism(newH, x, y);
                //set this zombie's city to null and reset counters
                this->city = NULL;
                this->breedCount = 0; //so it will not go to the breed routine
                this->starveClock = 0;
            }
            else { //still alive then try to move
                direction next = this->getNextMove();

                switch (next) {
                    case EAST:
                        //put the zombie to the new position
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
                    case NE:
                        city->setOrganism(this, x+1, y-1);
                        city->setOrganism(NULL, x-1, y+1);
                        break;
                    case NW:
                        city->setOrganism(this, x-1, y-1);
                        city->setOrganism(NULL, x+1, y+1);
                        break;
                    case SE:
                        city->setOrganism(this, x+1, y+1);
                        city->setOrganism(NULL, x-1, y-1);
                        break;
                    case SW:
                        city->setOrganism(this, x-1, y+1);
                        city->setOrganism(NULL, x+1, y-1);
                        break;
                    case STAY: //means STAY
                        break;
                } //end switch
            } //end else
        } //end if nothing to eat
        else { //Go to eat
            this->starveClock = 0; //reset stave counter

            switch (next) {
                case EAST:
                    //delete the human
                    delete city->getOrganism(x+1, y);
                    //put the zombie to that new position
                    city->setOrganism(this, x+1, y);
                    //put an empty space to the previous position;
                    city->setOrganism(NULL, x-1, y);
                    break;
                case WEST:
                    delete city->getOrganism(x-1, y);
                    city->setOrganism(this, x-1, y);
                    city->setOrganism(NULL, x+1, y);
                    break;
                case SOUTH:
                    delete city->getOrganism(x, y+1);
                    city->setOrganism(this, x, y+1);
                    city->setOrganism(NULL, x, y-1);
                    break;
                case NORTH:
                    delete city->getOrganism(x, y-1);
                    city->setOrganism(this, x, y-1);
                    city->setOrganism(NULL, x, y+1);
                    break;
                case NE:
                    delete city->getOrganism(x+1, y-1);
                    city->setOrganism(this, x+1, y-1);
                    city->setOrganism(NULL, x-1, y+1);
                    break;
                case NW:
                    delete city->getOrganism(x-1, y-1);
                    city->setOrganism(this, x-1, y-1);
                    city->setOrganism(NULL, x+1, y+1);
                    break;
                case SE:
                    delete city->getOrganism(x+1, y+1);
                    city->setOrganism(this, x+1, y+1);
                    city->setOrganism(NULL, x-1, y-1);
                    break;
                case SW:
                    delete city->getOrganism(x-1, y+1);
                    city->setOrganism(this, x-1, y+1);
                    city->setOrganism(NULL, x+1, y-1);
                    break;
            } //end switch
        } //end eat routine

        if (this->breedCount >= ZOMBIE_BREED) { //breed routine after eat/move
            direction next = this->getNextEat(); //look for a human

            if(next != STAY) {
                //create a new Zombie
                Zombie *newZ = new Zombie(city);
                newZ->endTurn(); //set the moved value to true so that it cannot move this time

                switch (next) {
                    case EAST:
                        //put the new zombie to that new position
                        city->setOrganism(newZ, x + 1, y);
                        break;
                    case WEST:
                        city->setOrganism(newZ, x - 1, y);
                        break;
                    case SOUTH:
                        city->setOrganism(newZ, x, y + 1);
                        break;
                    case NORTH:
                        city->setOrganism(newZ, x, y - 1);
                        break;
                    case NE:
                        city->setOrganism(newZ, x + 1, y - 1);
                        break;
                    case NW:
                        city->setOrganism(newZ, x - 1, y - 1);
                        break;
                    case SE:
                        city->setOrganism(newZ, x + 1, y + 1);
                        break;
                    case SW:
                        city->setOrganism(newZ, x - 1, y + 1);
                        break;
                } //end switch
            }
        }
    } //end if(!moved)
}

char Zombie::getSpecies()
{
    return species;
}