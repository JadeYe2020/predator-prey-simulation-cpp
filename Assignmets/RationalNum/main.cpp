#include <iostream>
#include <string>
#include <regex>
#include <vector>
#include "Rational.h"
using namespace std;

int main() {
    string restart; //to save user's input about whether to restart again.

    do {
        cout << "\nRational Class Testing" << endl;
        cout << "Begin testing." << endl;

        //instantiate a rational num using the default constructor
        Rational rnDefault;
        cout << rnDefault;
        //instantiate a rational num using the constructor with 1 int arg
        Rational rnOneArg(-7);
        cout << rnOneArg;
        //instantiate a rational num using the constructor with 2 args
        Rational rnTwoArgs(9, -6);
        cout << rnTwoArgs;

//        string frac1, frac2;
//        cout << "Enter first fraction:";
//        getline(cin, frac1);
        //instantiate 1st fraction using the constructor with a string
//        Rational rn1(frac1);


        cout << "End testing." << endl;
        cout << "\nEnter 'Y' to restart, or any other key to exit:";
        getline(cin, restart);
    } while(restart == "Y"); //keep restarting the testing until the user typed "Y"

    return 0;
}
