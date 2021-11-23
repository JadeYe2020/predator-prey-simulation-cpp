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
        cout << "Begin testing.\n" << endl;

        //instantiate a rational num using the default constructor
        Rational rnDefault;
        cout << rnDefault;
        //instantiate a rational num using the constructor with 1 int arg
        Rational rnOneArg(-7);
        cout << rnOneArg;
        //instantiate a rational num using the constructor with 2 args
        Rational rnTwoArgs(9, -6);
        cout << rnTwoArgs;

        string frac1, frac2;
        cout << "\nEnter the first fraction:";
        getline(cin, frac1);
        //instantiate 1st fraction using the constructor with a string
        Rational rn1(frac1);
        cout << "The first rational number is: ";
        cout << rn1;
        cout << "\nEnter the second fraction:";
        getline(cin, frac2);
        //instantiate 1st fraction using the constructor with a string
        Rational rn2(frac2);
        cout << "The second rational number is: ";
        cout << rn2;

        cout << "\nrn1 + rn2 = ";
        Rational rnAdd = rn1 + rn2;
        cout << rnAdd;

        cout << "\nrn1 - rn2 = ";
        Rational rnSub = rn1 - rn2;
        cout << rnSub;

        cout << "\nrn1 * rn2 = ";
        Rational rnMulti = rn1 * rn2;
        cout << rnMulti;

        cout << "\nrn1 / rn2 = ";
        Rational rnDiv = rn1 / rn2;
        cout << rnDiv;

        cout << "\nResult of rn1 < rn2 is: ";
        if(rn1 < rn2)
            cout << "true";
        else
            cout << "false";

        cout << "\nResult of rn1 > rn2 is: ";
        if(rn1 > rn2)
            cout << "true";
        else
            cout << "false";

        cout << "\nResult of rn1 == rn2 is: ";
        if(rn1 == rn2)
            cout << "true";
        else
            cout << "false";

        cout << "\nEnd testing." << endl;
        cout << "\nEnter 'Y' to restart, or any other key to exit:";
        getline(cin, restart);
    } while(restart == "Y"); //keep restarting the testing until the user typed "Y"

    return 0;
}
