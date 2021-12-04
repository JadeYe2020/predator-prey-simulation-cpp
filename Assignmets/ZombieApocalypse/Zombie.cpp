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

Zombie::Zombie() {}

Zombie::Zombie( City *city )
{
    species = ZOMBIE_CH;
    this->city = city;
    breedCount = 0;
    starveCount = 0;
}

Zombie::~Zombie() {
//    if(this->city != NULL)
//        this->city = NULL;
}

Zombie::direction Zombie::getNextEat() {

    vector<direction> spCanEat;
    //look for spaces with humans
    switch (x) {
        case 0:
            switch(y) {
                case 0: //check east, south and SE
                    if(city->getOrganism(x+1, y) != NULL) {
                        if(city->getOrganism(x+1, y)->getSpecies() == HUMAN_CH)
                            spCanEat.push_back(EAST);
                    }

                    if(city->getOrganism(x, y+1) != NULL) {
                        if(city->getOrganism(x, y+1)->getSpecies() == HUMAN_CH)
                            spCanEat.push_back(SOUTH);
                    }

                    if(city->getOrganism(x+1, y+1) != NULL) {
                        if(city->getOrganism(x+1, y+1)->getSpecies() == HUMAN_CH)
                            spCanEat.push_back(SE);
                    }
                    break;
                case GRIDSIZE-1: //check east, north and NE
                    if(city->getOrganism(x+1, y) != NULL) {
                        if(city->getOrganism(x+1, y)->getSpecies() == HUMAN_CH)
                            spCanEat.push_back(EAST);
                    }

                    if(city->getOrganism(x, y-1) != NULL) {
                        if(city->getOrganism(x, y-1)->getSpecies() == HUMAN_CH)
                            spCanEat.push_back(NORTH);
                    }

                    if(city->getOrganism(x+1, y-1) != NULL) {
                        if(city->getOrganism(x+1, y-1)->getSpecies() == HUMAN_CH)
                            spCanEat.push_back(NE);
                    }
                    break;
                default: //check east, north, south, NE, SE
                    if(city->getOrganism(x+1, y) != NULL) {
                        if(city->getOrganism(x+1, y)->getSpecies() == HUMAN_CH)
                            spCanEat.push_back(EAST);
                    }

                    if(city->getOrganism(x, y-1) != NULL) {
                        if(city->getOrganism(x, y-1)->getSpecies() == HUMAN_CH)
                            spCanEat.push_back(NORTH);
                    }

                    if(city->getOrganism(x+1, y-1) != NULL) {
                        if(city->getOrganism(x+1, y-1)->getSpecies() == HUMAN_CH)
                            spCanEat.push_back(NE);
                    }

                    if(city->getOrganism(x, y+1) != NULL) {
                        if(city->getOrganism(x, y+1)->getSpecies() == HUMAN_CH)
                            spCanEat.push_back(SOUTH);
                    }

                    if(city->getOrganism(x+1, y+1) != NULL) {
                        if(city->getOrganism(x+1, y+1)->getSpecies() == HUMAN_CH)
                            spCanEat.push_back(SE);
                    }
                    break;
            }
            break;
        case GRIDSIZE-1:
            switch(y) {
                case 0: //check west, south, SW
                    if(city->getOrganism(x-1, y) != NULL) {
                        if(city->getOrganism(x-1, y)->getSpecies() == HUMAN_CH)
                            spCanEat.push_back(WEST);
                    }

                    if(city->getOrganism(x, y+1) != NULL) {
                        if(city->getOrganism(x, y+1)->getSpecies() == HUMAN_CH)
                            spCanEat.push_back(SOUTH);
                    }

                    if(city->getOrganism(x-1, y+1) != NULL) {
                        if(city->getOrganism(x-1, y+1)->getSpecies() == HUMAN_CH)
                            spCanEat.push_back(SW);
                    }
                    break;
                case GRIDSIZE-1: //check west, north, NW
                    if(city->getOrganism(x-1, y) != NULL) {
                        if(city->getOrganism(x-1, y)->getSpecies() == HUMAN_CH)
                            spCanEat.push_back(WEST);
                    }

                    if(city->getOrganism(x, y-1) != NULL) {
                        if(city->getOrganism(x, y-1)->getSpecies() == HUMAN_CH)
                            spCanEat.push_back(NORTH);
                    }

                    if(city->getOrganism(x-1, y-1) != NULL) {
                        if(city->getOrganism(x-1, y-1)->getSpecies() == HUMAN_CH)
                            spCanEat.push_back(NW);
                    }
                    break;
                default: //check west, north, south, NW, SW
                    if(city->getOrganism(x-1, y) != NULL) {
                        if(city->getOrganism(x-1, y)->getSpecies() == HUMAN_CH)
                            spCanEat.push_back(WEST);
                    }

                    if(city->getOrganism(x, y-1) != NULL) {
                        if(city->getOrganism(x, y-1)->getSpecies() == HUMAN_CH)
                            spCanEat.push_back(NORTH);
                    }

                    if(city->getOrganism(x-1, y-1) != NULL) {
                        if(city->getOrganism(x-1, y-1)->getSpecies() == HUMAN_CH)
                            spCanEat.push_back(NW);
                    }

                    if(city->getOrganism(x, y+1) != NULL) {
                        if(city->getOrganism(x, y+1)->getSpecies() == HUMAN_CH)
                            spCanEat.push_back(SOUTH);
                    }

                    if(city->getOrganism(x-1, y+1) != NULL) {
                        if(city->getOrganism(x-1, y+1)->getSpecies() == HUMAN_CH)
                            spCanEat.push_back(SW);
                    }
                    break;
            }
            break;
        default:
            switch(y) {
                case 0: //check east, west, south, SE, SW
                    if(city->getOrganism(x+1, y) != NULL) {
                        if(city->getOrganism(x+1, y)->getSpecies() == HUMAN_CH)
                            spCanEat.push_back(EAST);
                    }

                    if(city->getOrganism(x-1, y) != NULL) {
                        if(city->getOrganism(x-1, y)->getSpecies() == HUMAN_CH)
                            spCanEat.push_back(WEST);
                    }

                    if(city->getOrganism(x, y+1) != NULL) {
                        if(city->getOrganism(x, y+1)->getSpecies() == HUMAN_CH)
                            spCanEat.push_back(SOUTH);
                    }

                    if(city->getOrganism(x+1, y+1) != NULL) {
                        if(city->getOrganism(x+1, y+1)->getSpecies() == HUMAN_CH)
                            spCanEat.push_back(SE);
                    }

                    if(city->getOrganism(x-1, y+1) != NULL) {
                        if(city->getOrganism(x-1, y+1)->getSpecies() == HUMAN_CH)
                            spCanEat.push_back(SW);
                    }
                    break;
                case GRIDSIZE-1: //check east, west, north, NE, NW
                    if(city->getOrganism(x+1, y) != NULL) {
                        if(city->getOrganism(x+1, y)->getSpecies() == HUMAN_CH)
                            spCanEat.push_back(EAST);
                    }

                    if(city->getOrganism(x-1, y) != NULL) {
                        if(city->getOrganism(x-1, y)->getSpecies() == HUMAN_CH)
                            spCanEat.push_back(WEST);
                    }

                    if(city->getOrganism(x, y-1) != NULL) {
                        if(city->getOrganism(x, y-1)->getSpecies() == HUMAN_CH)
                            spCanEat.push_back(NORTH);
                    }

                    if(city->getOrganism(x-1, y-1) != NULL) {
                        if(city->getOrganism(x-1, y-1)->getSpecies() == HUMAN_CH)
                            spCanEat.push_back(NW);
                    }

                    if(city->getOrganism(x+1, y-1) != NULL) {
                        if(city->getOrganism(x+1, y-1)->getSpecies() == HUMAN_CH)
                            spCanEat.push_back(NE);
                    }
                    break;
                default: //check all 8 directions
                    if(city->getOrganism(x+1, y) != NULL) {
                        if(city->getOrganism(x+1, y)->getSpecies() == HUMAN_CH)
                            spCanEat.push_back(EAST);
                    }

                    if(city->getOrganism(x-1, y) != NULL) {
                        if(city->getOrganism(x-1, y)->getSpecies() == HUMAN_CH)
                            spCanEat.push_back(WEST);
                    }

                    if(city->getOrganism(x, y-1) != NULL) {
                        if(city->getOrganism(x, y-1)->getSpecies() == HUMAN_CH)
                            spCanEat.push_back(NORTH);
                    }

                    if(city->getOrganism(x+1, y-1) != NULL) {
                        if(city->getOrganism(x+1, y-1)->getSpecies() == HUMAN_CH)
                            spCanEat.push_back(NE);
                    }

                    if(city->getOrganism(x-1, y-1) != NULL) {
                        if(city->getOrganism(x-1, y-1)->getSpecies() == HUMAN_CH)
                            spCanEat.push_back(NW);
                    }

                    if(city->getOrganism(x, y+1) != NULL) {
                        if(city->getOrganism(x, y+1)->getSpecies() == HUMAN_CH)
                            spCanEat.push_back(SOUTH);
                    }

                    if(city->getOrganism(x+1, y+1) != NULL) {
                        if(city->getOrganism(x+1, y+1)->getSpecies() == HUMAN_CH)
                            spCanEat.push_back(SE);
                    }

                    if(city->getOrganism(x-1, y+1) != NULL) {
                        if(city->getOrganism(x-1, y+1)->getSpecies() == HUMAN_CH)
                            spCanEat.push_back(SW);
                    }
                    break;
            }
            break;
    } // end switch(x)

    if(spCanEat.size() > 0) {
        //shuffle vector
        unsigned seed = chrono::system_clock::now().time_since_epoch().count();
        shuffle(spCanEat.begin(), spCanEat.end(), default_random_engine(seed));
        return spCanEat[0];
    }
    else
        return STAY;
}

Zombie::direction Zombie::getNextMove() {

    vector<direction> spCanMove;
    //look for empty spaces
    switch (x) {
        case 0:
            switch(y) {
                case 0: //check east, south and SE
                    if(city->getOrganism(x+1, y) == NULL)
                        spCanMove.push_back(EAST);
                    if(city->getOrganism(x, y+1) == NULL)
                        spCanMove.push_back(SOUTH);
                    if(city->getOrganism(x+1, y+1) == NULL)
                        spCanMove.push_back(SE);
                    break;
                case GRIDSIZE-1: //check east, north and NE
                    if(city->getOrganism(x+1, y) == NULL)
                        spCanMove.push_back(EAST);
                    if(city->getOrganism(x, y-1) == NULL)
                        spCanMove.push_back(NORTH);
                    if(city->getOrganism(x+1, y-1) == NULL)
                        spCanMove.push_back(NE);
                    break;
                default: //check east, north, south, NE, SE
                    if(city->getOrganism(x+1, y) == NULL)
                        spCanMove.push_back(EAST);
                    if(city->getOrganism(x, y-1) == NULL)
                        spCanMove.push_back(NORTH);
                    if(city->getOrganism(x+1, y-1) == NULL)
                        spCanMove.push_back(NE);
                    if(city->getOrganism(x, y+1) == NULL)
                        spCanMove.push_back(SOUTH);
                    if(city->getOrganism(x+1, y+1) == NULL)
                        spCanMove.push_back(SE);
                    break;
            }
            break;
        case GRIDSIZE-1:
            switch(y) {
                case 0: //check west, south, SW
                    if(city->getOrganism(x-1, y) == NULL)
                        spCanMove.push_back(WEST);
                    if(city->getOrganism(x, y+1) == NULL)
                        spCanMove.push_back(SOUTH);
                    if(city->getOrganism(x-1, y+1) == NULL)
                        spCanMove.push_back(SW);
                    break;
                case GRIDSIZE-1: //check west, north, NW
                    if(city->getOrganism(x-1, y) == NULL)
                        spCanMove.push_back(WEST);
                    if(city->getOrganism(x, y-1) == NULL)
                        spCanMove.push_back(NORTH);
                    if(city->getOrganism(x-1, y-1) == NULL)
                        spCanMove.push_back(NW);
                    break;
                default: //check west, north, south, NW, SW
                    if(city->getOrganism(x-1, y) == NULL)
                        spCanMove.push_back(WEST);
                    if(city->getOrganism(x, y-1) == NULL)
                        spCanMove.push_back(NORTH);
                    if(city->getOrganism(x-1, y-1) == NULL)
                        spCanMove.push_back(NW);
                    if(city->getOrganism(x, y+1) == NULL)
                        spCanMove.push_back(SOUTH);
                    if(city->getOrganism(x-1, y+1) == NULL)
                        spCanMove.push_back(SW);
                    break;
            }
            break;
        default:
            switch(y) {
                case 0: //check east, west, south, SE, SW
                    if(city->getOrganism(x+1, y) == NULL)
                        spCanMove.push_back(EAST);
                    if(city->getOrganism(x-1, y) == NULL)
                        spCanMove.push_back(WEST);
                    if(city->getOrganism(x, y+1) == NULL)
                        spCanMove.push_back(SOUTH);
                    if(city->getOrganism(x+1, y+1) == NULL)
                        spCanMove.push_back(SE);
                    if(city->getOrganism(x-1, y+1) == NULL)
                        spCanMove.push_back(SW);
                    break;
                case GRIDSIZE-1: //check east, west, north, NE, NW
                    if(city->getOrganism(x+1, y) == NULL)
                        spCanMove.push_back(EAST);
                    if(city->getOrganism(x-1, y) == NULL)
                        spCanMove.push_back(WEST);
                    if(city->getOrganism(x, y-1) == NULL)
                        spCanMove.push_back(NORTH);
                    if(city->getOrganism(x+1, y-1) == NULL)
                        spCanMove.push_back(NE);
                    if(city->getOrganism(x-1, y-1) == NULL)
                        spCanMove.push_back(NW);
                    break;
                default: //check all 8 directions
                    if(city->getOrganism(x+1, y) == NULL)
                        spCanMove.push_back(EAST);
                    if(city->getOrganism(x-1, y) == NULL)
                        spCanMove.push_back(WEST);
                    if(city->getOrganism(x, y-1) == NULL)
                        spCanMove.push_back(NORTH);
                    if(city->getOrganism(x+1, y-1) == NULL)
                        spCanMove.push_back(NE);
                    if(city->getOrganism(x-1, y-1) == NULL)
                        spCanMove.push_back(NW);
                    if(city->getOrganism(x, y+1) == NULL)
                        spCanMove.push_back(SOUTH);
                    if(city->getOrganism(x+1, y+1) == NULL)
                        spCanMove.push_back(SE);
                    if(city->getOrganism(x-1, y+1) == NULL)
                        spCanMove.push_back(SW);
                    break;
            }
            break;
    } // end switch(x)

    if(spCanMove.size() > 0) {
        //shuffle vector
        unsigned seed = chrono::system_clock::now().time_since_epoch().count();
        shuffle(spCanMove.begin(), spCanMove.end(), default_random_engine(seed));
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
            this->starveCount ++;

            if(starveCount == 3) { //too starved to be a zombie anymore
                //set a new Human on the same location
                Human *newH = new Human(city);
                newH->endTurn(); //set the moved value to true so that it cannot move this time
                city->setOrganism(newH, x, y);
                //set this zombie's city to null
                this->city = NULL;
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
            this->starveCount = 0; //reset stave counter

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

        if (this->breedCount >= 8) { //breed routine after eat/move
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