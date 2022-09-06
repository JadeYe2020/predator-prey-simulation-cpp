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

using namespace std;

void makeCity(City *city, int numOfH, int numOfZ);

void ClearScreen()
{
    cout << "\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n";
}

int main() {
    //instantiate a new City on heap
    City *city = new City();
    //call a customized method to randomly populate the city with set numbers of Humans and Zombies
    makeCity(city, HUMAN_STARTCOUNT, ZOMBIE_STARTCOUNT);

    //print the generation 0 city
    cout << *city;
    int genCount = 0;
    int numOfH = city->countType(HUMAN_CH);
    int numOfZ = city->countType(ZOMBIE_CH);
    cout << "GENERATION " << genCount << "\t";
    cout << "HUMANS: " << numOfH << "\t";
    cout << "ZOMBIES: " << numOfZ << endl;

    chrono:: milliseconds interval(INTERVAL);

    do {
        this_thread::sleep_for(interval); //pause for 900 milliseconds
        ClearScreen();

        city->move(); //includes all actions

        city->reset(); //resets moved flags
        genCount ++; //increment the generation counter
        //count humans and zombies respectively
        numOfH = city->countType(HUMAN_CH);
        numOfZ = city->countType(ZOMBIE_CH);

        cout << *city; //print the city with its new info
        cout << "GENERATION " << genCount << "\t";
        cout << "HUMANS: " << numOfH << "\t";
        cout << "ZOMBIES: " << numOfZ << endl;

    } while( numOfH > 0 && numOfZ > 0 && genCount < ITERATIONS); //while both humans and zombies exist; no more than 1000 iterations

    if(genCount != ITERATIONS)
        cout << "Extinction Event - End Program" << endl;
    else if(numOfH > 0 || numOfZ > 0)
        cout << "1000 iterations finished - End Program" << endl;
    else
        cout << "Extinction Event happens at the 1000th iteration - End Program" << endl;

    return 0;
}

void makeCity(City *city, int numOfH, int numOfZ) {
    if (numOfH + numOfZ <= GRIDSIZE * GRIDSIZE)
    {
        //create a vector to hold all the spaces (i.e., nullptrs) inside the grid first
        vector<Organism*> vOrg(GRIDSIZE * GRIDSIZE - numOfH - numOfZ);
        //add into the vector: 100 humans and 5 Zombies
        for(int i=0; i<HUMAN_STARTCOUNT; i++)
        {
            Human *hm = new Human(city);
            vOrg.push_back((Organism*)hm); //upcasting
        }
        for(int i=0; i<ZOMBIE_STARTCOUNT; i++)
        {
            Zombie *zb = new Zombie(city);
            vOrg.push_back((Organism*)zb); //upcasting
        }

        //shuffle the fully populated vector
        unsigned seed = chrono::system_clock::now().time_since_epoch().count();//create random seed using system clock
        shuffle(vOrg.begin(), vOrg.end(), default_random_engine(seed));

        //populate the city with Organisms and nullptrs in a random fashion
        int k = 0;
        for(int i=0; i<GRIDSIZE; i++) {
            for(int j=0; j<GRIDSIZE; j++) {
                //if it's an Organism object, set it into the position
                if(vOrg[k] != NULL)
                    city->setOrganism(vOrg[k], j, i);
                //otherwise, do nothing and move on to the next item
                k++;
            }
        }
    }
}
