#include <iostream>
#include <string>
#include <regex>
#include <sstream>
#include <vector>
#include <chrono>
#include <thread>
using namespace std;

void ClearScreen()
{
    cout << "\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n";
}

int main() {

//    City *city = new City();
    chrono:: milliseconds interval(900);

    for(int i=0; i<10; i++) { //while both humans and zombies exist
        this_thread::sleep_for(interval);
        ClearScreen();
//        city->move(); //includes all actions

        cout << "GENERATION " << (i+1) << endl;

//        city->reset(); //resets moved flags
//        city->countOrganisms(Z or H goes here);// run once for each type
//        cout << *city; //prints city
//        cout << "GENERATION " << city->getGeneration() << endl;
//        cout << "HUMANS: " << city->countType(HUMAN_CH) << endl;
//        cout << "ZOMBIES: " << city->countType(ZOMBIE_CH) << endl;
    }//end while
    cout << "Extinction Event - End Program" << endl;

    return 0;
}