// Reference: Example main.cpp created by W0068332 on 11/21/2021.

#include <iostream>
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
    cout << "\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n";
}

int main() {

    City *city = new City();
    //populate the city with creatures
    for(int i=0; i<GRIDSIZE; i++) {
        for(int j=0; j<GRIDSIZE; j++) {
            Human *hm = new Human;

            city->setOrganism((Organism*)hm, i, j);
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

//        city->reset(); //resets moved flags
//        city->countOrganisms(Z or H goes here);// run once for each type
        cout << *city; //prints city
        cout << "GENERATION " << (i+1) << endl;
//        cout << "GENERATION " << city->getGeneration() << endl;
//        cout << "HUMANS: " << city->countType(HUMAN_CH) << endl;
//        cout << "ZOMBIES: " << city->countType(ZOMBIE_CH) << endl;
    }//end while
    cout << "Extinction Event - End Program" << endl;

    return 0;
}
