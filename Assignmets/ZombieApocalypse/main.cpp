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
    cout << "\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n";
}

void popCity(City *city, int numOfH, int numOfZ);

int main() {

    City *city = new City();
    //call a customized method to populate the city with set numbers of Humans and Zombies
    popCity(city, HUMAN_STARTCOUNT, ZOMBIE_STARTCOUNT);


    cout << *city; //prints city
    int genCount = 0;
    int numOfH = city->countType(HUMAN_CH);
    int numOfZ = city->countType(ZOMBIE_CH);
    cout << "GENERATION " << genCount << "\t";
    cout << "HUMANS: " << numOfH << "\t";
    cout << "ZOMBIES: " << numOfZ << endl;

    chrono:: milliseconds interval(INTERVAL);

//    for(int i=0; i<12; i++) {
    do {
        this_thread::sleep_for(interval);
        ClearScreen();

        city->move(); //includes all actions

        city->reset(); //resets moved flags
        genCount ++; //increment the generation counter
        numOfH = city->countType(HUMAN_CH);
        numOfZ = city->countType(ZOMBIE_CH);

        cout << *city; //prints city
        cout << "GENERATION " << genCount << "\t";
        cout << "HUMANS: " << numOfH << "\t";
        cout << "ZOMBIES: " << numOfZ << endl;
    } while( numOfH > 0 && numOfZ > 0 && genCount < ITERATIONS); //while both humans and zombies exist; no more than 1000 iterations

    if(genCount != ITERATIONS)
        cout << "Extinction Event - End Program" << endl;
    else
        cout << "1000 iterations finished - End Program" << endl;

    return 0;
}

void popCity(City *city, int numOfH, int numOfZ) {
    if (numOfH + numOfZ <= GRIDSIZE * GRIDSIZE)
    {
        //create a vector to hold all nullptrs inside the grid first
        vector<Organism*> vOrg(GRIDSIZE * GRIDSIZE - numOfH - numOfZ);
        //add into the vector: 100 humans and 5 Zombies
        for(int i=0; i<HUMAN_STARTCOUNT; i++)
        {
            Human *hm = new Human(city);
            vOrg.push_back((Organism*)hm);
        }
        for(int i=0; i<ZOMBIE_STARTCOUNT; i++)
        {
            Zombie *zb = new Zombie(city);
            vOrg.push_back((Organism*)zb);
        }

        //shuffle the fully populated vector
        unsigned seed = chrono::system_clock::now().time_since_epoch().count();//create random seed using system clock
        shuffle(vOrg.begin(), vOrg.end(), default_random_engine(seed));

        //populate the city with Organisms and nullptrs in a random fashion
        int k = 0;
        for(int i=0; i<GRIDSIZE; i++) {
            for(int j=0; j<GRIDSIZE; j++) {
                if(vOrg[k] != NULL)
                    city->setOrganism(vOrg[k], j, i);
                k++;
            }
        }
    }

}
