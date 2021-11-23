// This is the implementation file
// Created by JadeYe on 11/22/2021.

#include <iostream>
#include <string>
#include <regex>
#include <vector>
#include <sstream>
#include "Rational.h"
using namespace std;

vector<string> split(string fraction);

//default constructor
Rational::Rational(): numerator(0), denominator(1)
{
    cout << "{Default Constructor Fired}" << endl;
}

//constructor with one arg
Rational::Rational(int wholeNum) {
    cout << "{Constructor with 1 arg Fired}" << endl;
    numerator = wholeNum;
    denominator = 1;
}

//constructor with two args
Rational::Rational(int numer, int denomin) {
    cout << "{Constructor with 2 args Fired}" << endl;
    numerator = numer;
    denominator = denomin;
}

//constructor with a string
Rational::Rational(string fraction) {
    cout << "{Constructor with a string Fired}" << endl;

    vector<string> fracNum = split(fraction);

    istringstream(fracNum[0]) >> numerator;
    istringstream(fracNum[1]) >> denominator;
}

//normalization method
Rational Rational::normalize(int numer, int denomin) {
    /////////////////////////////////
    ///////////////////////////////////
    return Rational(numer, denomin);
}

//operator + overloading
Rational Rational::operator+ (Rational &rightSide)
{
    this->numerator = this->numerator * rightSide.denominator + rightSide.numerator * this->denominator;
    this->denominator = this->denominator * rightSide.denominator;

    return *this;
}
//operator - overloading
Rational Rational::operator- (Rational &rightSide)
{
    this->numerator = this->numerator * rightSide.denominator - rightSide.numerator * this->denominator;
    this->denominator = this->denominator * rightSide.denominator;

    return *this;
}
//operator * overloading
Rational Rational::operator* (Rational &rightSide)
{
    this->numerator = this->numerator * rightSide.numerator;
    this->denominator = this->denominator * rightSide.denominator;

    return *this;
}
//operator / overloading
Rational Rational::operator/ (Rational &rightSide)
{
    this->numerator = this->numerator * rightSide.denominator;
    this->denominator = this->denominator * rightSide.numerator;

    return *this;
}

//operator > overloading
bool Rational::operator> (Rational &rightSide)
{
    if(this->numerator * rightSide.denominator > rightSide.numerator * this->denominator)
        return true;
    else
        return false;
}
//operator < overloading
bool Rational::operator< (Rational &rightSide)
{
    if(this->numerator * rightSide.denominator < rightSide.numerator * this->denominator)
        return true;
    else
        return false;
}
//operator == overloading
bool Rational::operator== (Rational &rightSide)
{
    if(this->numerator * rightSide.denominator == rightSide.numerator * this->denominator)
        return true;
    else
        return false;
}

//output operator overloading
ostream& operator<< (ostream &output, Rational &rn)
{
    cout << "{<< operator fired}" << endl;
    //build a string for the rational number
    string str = to_string(rn.numerator) + "/" + to_string(rn.denominator);
    //put the string into the output stream
    output << str << endl;
    //return the output stream
    return output;
}

vector<string> split(string fraction) //source: https://stackoverflow.com/questions/9435385/split-a-string-using-c11
{
    regex token("/");
    sregex_token_iterator numer{fraction.begin(), fraction.end(), token, -1},
            denomin;

    return vector<string> {numer, denomin};
}