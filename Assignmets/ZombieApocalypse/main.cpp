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

int main() {

    City *city = new City();

    vector<Organism*> vOrg(GRIDSIZE * GRIDSIZE - HUMAN_STARTCOUNT - ZOMBIE_STARTCOUNT); //should have 8 nullptrs
    //populate vector: , 9 humans and 4 Zombies
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

    //shuffle
    unsigned seed = chrono::system_clock::now().time_since_epoch().count();//create random seed using system clock
    shuffle(vOrg.begin(), vOrg.end(), default_random_engine(seed));

    //populate the city with creatures
    int k = 0;
    for(int i=0; i<GRIDSIZE; i++) {
        for(int j=0; j<GRIDSIZE; j++) {
            if(vOrg[k] != NULL)
                city->setOrganism(vOrg[k], j, i);
            k++;
        }
    }

    cout << *city; //prints city
    int genCount = 0;
    int numOfH = city->countType(HUMAN_CH);
    int numOfZ = city->countType(ZOMBIE_CH);
    cout << "GENERATION " << genCount << "\t";
    cout << "HUMANS: " << numOfH << "\t";
    cout << "ZOMBIES: " << numOfZ << endl;

    chrono:: milliseconds interval(INTERVAL);

//    for(int i=0; i<12; i++) { //while both humans and zombies exist
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
    } while( numOfH > 0 && numOfZ > 0 && genCount < ITERATIONS);

    if(genCount != ITERATIONS)
        cout << "Extinction Event - End Program" << endl;
    else
        cout << "1000 iterations finished - End Program" << endl;

    return 0;
}
