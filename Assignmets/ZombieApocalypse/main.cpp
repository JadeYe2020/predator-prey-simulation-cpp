// Reference: Example main.cpp created by W0068332 on 11/21/2021.

#include <iostream>
#include <vector>
#include <algorithm>
#include <random>
#include <chrono>
#include <thread>
#include "GameSpecs.h"
#include "Organism.h"
#include "City.h"
#include "Human.h"
#include "Zombie.h"

using namespace std;

void ClearScreen()
{
//    cout << "\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n";
    cout << "\n\n";
}

int main() {

    City *city = new City();

    vector<Organism*> vOrg(GRIDSIZE * GRIDSIZE - 8 - 4); //should have 8 nullptrs
    //populate vector: , 9 humans and 4 Zombies
    for(int i=0; i<8; i++)
    {
        Human *hm = new Human(city);
        vOrg.push_back((Organism*)hm);
    }
    for(int i=0; i<4; i++)
    {
        Zombie *zb = new Zombie(city);
        vOrg.push_back((Organism*)zb);
    }

    //shuffle
    unsigned seed = chrono::system_clock::now().time_since_epoch().count();//create random seed using system clock
    shuffle(vOrg.begin(), vOrg.end(), default_random_engine(seed));

    //populate the city with creatures
    int k = 0;
    for(int i=0; i<GRIDSIZE; i++) {
        for(int j=0; j<GRIDSIZE; j++) {
            city->setOrganism(vOrg[k], j, i);
            if(vOrg[k] != NULL)
                vOrg[k]->setPosition(j, i);

            k++;
        }
    }

    chrono:: milliseconds interval(INTERVAL);

    for(int i=0; i<5; i++) { //while both humans and zombies exist
        this_thread::sleep_for(interval);
        ClearScreen();
//        city->move(); //includes all actions

        // Alternate multi-pass version with each activity happening in its own
// pass through the array. Lends itself to prototyping and testing:
        //   city->humansMove();
        //   city->zombiesMoveEat();
        //   city->humansRecruit();
        //   city->zombiesRecruit();
        //   city->zombiesStarve();
        //   city->countOrganisms(Z or H goes here);

        city->reset(); //resets moved flags
//        city->countOrganisms(Z or H goes here);// run once for each type
        cout << *city; //prints city
        cout << "GENERATION " << (i+1) << "\t";
        cout << "HUMANS: " << city->countType(HUMAN_CH) << "\t";
        cout << "ZOMBIES: " << city->countType(ZOMBIE_CH) << endl;


        city->move();

//        cout << "GENERATION " << city->getGeneration() << endl;

    }//end while
    cout << "Extinction Event - End Program" << endl;

    return 0;
}
