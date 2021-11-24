// Rational header file
// This is the interface for the Student class
// Created by JadeYe on 11/22/2021.
//

#ifndef RATIONALNUM_RATIONAL_H
#define RATIONALNUM_RATIONAL_H
#include <string>
using namespace std;

class Rational
{
    private:
        int numerator;
        int denominator;

    public:
        //default constructor
        Rational();
        //constructor with one arg
        Rational(int wholeNum);
        //constructor with two args
        Rational(int numer, int denomin);
        //constructor with a string
        Rational(string fraction);

        //get method for numerator value
        int getNumerator();

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
        friend ostream& operator<< (ostream &output, Rational &rn);
};

#endif //RATIONALNUM_RATIONAL_H
