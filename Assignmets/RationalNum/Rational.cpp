// This is the implementation file
// Created by JadeYe on 11/22/2021.

#include <iostream>
#include <string>
#include <regex>
#include <vector>
#include <sstream>
#include <algorithm> //to get __gcd() method
#include "Rational.h"
using namespace std;

vector<string> split(string fraction);
void normalize(int& numer, int& denomin);

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
    normalize(numer, denomin);

    numerator = numer;
    denominator = denomin;
}

//constructor with a string
Rational::Rational(string fraction) {
    cout << "{Constructor with a string Fired}" << endl;

    vector<string> fracNum = split(fraction);

    istringstream(fracNum[0]) >> numerator;
    istringstream(fracNum[1]) >> denominator;

    normalize(numerator, denominator);
}

//operator + overloading
Rational Rational::operator+ (Rational &rightSide)
{
    cout << "{Overloaded + operator Fired}" << endl;
    int newNumer = this->numerator * rightSide.denominator + rightSide.numerator * this->denominator;
    int newDenomin = this->denominator * rightSide.denominator;

    normalize(newNumer, newDenomin);
    return Rational(newNumer, newDenomin);
}
//operator - overloading
Rational Rational::operator- (Rational &rightSide)
{
    cout << "{Overloaded - operator Fired}" << endl;
    int newNumer = this->numerator * rightSide.denominator - rightSide.numerator * this->denominator;
    int newDenomin = this->denominator * rightSide.denominator;

    normalize(newNumer, newDenomin);
    return Rational(newNumer, newDenomin);
}
//operator * overloading
Rational Rational::operator* (Rational &rightSide)
{
    cout << "{Overloaded * operator Fired}" << endl;
    int newNumer = this->numerator * rightSide.numerator;
    int newDenomin = this->denominator * rightSide.denominator;

    normalize(newNumer, newDenomin);
    return Rational(newNumer, newDenomin);
}
//operator / overloading
Rational Rational::operator/ (Rational &rightSide)
{
    cout << "{Overloaded / operator Fired}" << endl;
    int newNumer = this->numerator * rightSide.denominator;
    int newDenomin = this->denominator * rightSide.numerator;

    normalize(newNumer, newDenomin);
    return Rational(newNumer, newDenomin);
}

//operator > overloading
bool Rational::operator> (Rational &rightSide)
{
    cout << "{Overloaded > operator Fired}" << endl;
    if(this->numerator * rightSide.denominator > rightSide.numerator * this->denominator)
        return true;
    else
        return false;
}
//operator < overloading
bool Rational::operator< (Rational &rightSide)
{
    cout << "{Overloaded < operator Fired}" << endl;
    if(this->numerator * rightSide.denominator < rightSide.numerator * this->denominator)
        return true;
    else
        return false;
}
//operator == overloading
bool Rational::operator== (Rational &rightSide)
{
    cout << "{Overloaded == operator Fired}" << endl;
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

void normalize(int& numer, int& denomin)
{
    //get the greatest common divisor of the numerator and denominator
    //source: https://www.geeksforgeeks.org/stdgcd-c-inbuilt-function-finding-gcd/
    int gcd = __gcd(numer, denomin);
    //update the values accordingly
    numer = numer / gcd;
    denomin = denomin / gcd;

    if(denomin < 0) {
        numer *= -1;
        denomin *= -1;
    }
}