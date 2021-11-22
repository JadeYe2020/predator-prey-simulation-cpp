// This is the implementation file
// Created by JadeYe on 11/22/2021.

#include <iostream>
#include <string>
#include <regex>
#include "Rational.h"
using namespace std;



//default constructor
Rational::Rational()
{
    numerator = 0;
    denominator = 1;
}

//constructor with one arg
Rational::Rational(int wholeNum) {
    numerator = wholeNum;
    denominator = 1;
}

//constructor with two args
Rational::Rational(int numer, int denomin) {
    numerator = numer;
    denominator = denomin;
}

//constructor with a string
Rational::Rational(string fraction) {

}
//normalization method
Rational normalize(int numer, int denomin);

//operator + overloading
Rational operator+ (Rational &rightSide);
//operator - overloading
Rational operator- (Rational &rightSide);
//operator * overloading
Rational operator* (Rational &rightSide);
//operator / overloading
Rational operator/ (Rational &rightSide);

//operator > overloading
bool operator> (Rational &rightSide);
//operator < overloading
bool operator< (Rational &rightSide);
//operator == overloading
bool operator== (Rational &rightSide);

//output operater overloading
friend ostream& operator<< (ostream&, Rational rn);