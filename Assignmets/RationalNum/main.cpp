#include <iostream>
#include <string>
#include <regex>
#include <vector>
#include "Rational.h"
using namespace std;

string askForFraction();

int main() {
    string restart; //to save user's input about whether to restart again.

    do {
        cout << "\nRational Class Testing" << endl;
        cout << "Begin testing." << endl;

        cout << "\nThe result of the Default Contrustor: ";
        //instantiate a rational num using the default constructor
        Rational rnDefault;
        cout << rnDefault;

        cout << "\nThe result of the Contrustor with 1 argument (whole number -7): ";
        //instantiate a rational num using the constructor with 1 int arg
        Rational rnOneArg(-7);
        cout << rnOneArg;

        cout << "\nThe result of the Contrustor with 2 arguments (numerator: 9, denominator: -6): ";
        //instantiate a rational num using the constructor with 2 args
        Rational rnTwoArgs(9, -6);
        cout << rnTwoArgs;

        cout << "\n\nTest the constructor with a string argument and overloaded operators:\n";

        string frac1, frac2;
        cout << "Enter the first fraction:";
        frac1 = askForFraction();
        //instantiate 1st fraction using the constructor with a string
        Rational rn1(frac1);

        cout << "\tEnter the second fraction:";
        frac2 = askForFraction();
        //instantiate 1st fraction using the constructor with a string
        Rational rn2(frac2);
        //make sure rn2 does not equal to 0, before doing the division calculation
        while (rn2.getNumerator() == 0) {
            cout << "The second rational number equals 0. Cannot perform division.\nPlease enter a new fraction:";
            frac2 = askForFraction();
            rn2 = Rational(frac2);
        }

        cout << "\nResult of the overloaded operator + :\n";
        //calculate and print out the results accordingly
        Rational rnAdd = rn1 + rn2;
        cout << rn1;
        cout << " + ";
        cout << rn2;
        cout << " = ";
        cout << rnAdd;

        cout << "\nResult of the overloaded operator - :\n";
        Rational rnSub = rn1 - rn2;
        cout << rn1;
        cout << " - ";
        cout << rn2;
        cout << " = ";
        cout << rnSub;

        cout << "\nResult of the overloaded operator * :\n";
        Rational rnMulti = rn1 * rn2;
        cout << rn1;
        cout << " * ";
        cout << rn2;
        cout << " = ";
        cout << rnMulti;

        cout << "\nResult of the overloaded operator - :\n";
        Rational rnDiv = rn1 / rn2;
        cout << rn1;
        cout << " / ";
        cout << rn2;
        cout << " = ";
        cout << rnDiv;

        cout << "\n\nResult of the comparison between the two rational numbers is: ";
        cout << rn1;
        //confirm the sign
        if(rn1 == rn2)
            cout << " = ";
        else if(rn1 < rn2)
            cout << " < ";
        else if(rn1 > rn2)
            cout << " > ";
        //print out the second ratioinal number
        cout << rn2;

        cout << "\n\nEnd testing." << endl;
        cout << "\nEnter 'Q' to exit, or any other key to restart:";
        getline(cin, restart);
    } while(restart != "Q"); //keep restarting the testing until the user typed "Q"

    return 0;
}

string askForFraction() {
    string fraction;

    getline(cin, fraction);

    //regex pattern for valid fraction numbers (https://www.geeksforgeeks.org/regex-regular-expression-in-c/)
    regex pattern("-?[0-9]+(/-?([1-9]+[0-9]*|[0]*[1-9]+[0-9]*))?");

    /*if it is not a valid fraction number, then ask the user to re-enter another one until a valid input is given.*/
    while(!regex_match(fraction, pattern))
    {
        cout << "This is not a valid fraction. Please enter again:";
        getline(cin, fraction);
    }

    return fraction;
}