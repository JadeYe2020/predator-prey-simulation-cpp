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

}

//constructor with one arg
Rational::Rational(int wholeNum) {
    numerator = wholeNum;
    denominator = 1;
}

//constructor with two args
Rational::Rational(int numer, int denomin) {
    normalize(numer, denomin);

    numerator = numer;
    denominator = denomin;
}

//constructor with a string
Rational::Rational(string fraction) {

    if(fraction.find('/') != string::npos) //source: https://java2blog.com/check-if-string-contains-substring-cpp/
    {   //when the user enter a fraction string instead of a whole number, we call the split function.
        //source: https://stackoverflow.com/questions/9435385/split-a-string-using-c11
        vector<string> fracNum = split(fraction);

        istringstream(fracNum[0]) >> numerator;
        istringstream(fracNum[1]) >> denominator;

        normalize(numerator, denominator);
    }
    else
    {
        //if the user enters a whole number then just put the number as the numerator and denominator should be 1.
        istringstream(fraction) >> numerator;
        denominator = 1;
    }
}

//get method for numerator value
int Rational::getNumerator() {
    return numerator;
}

//operator + overloading
Rational Rational::operator+ (Rational &rightSide)
{
    int newNumer = this->numerator * rightSide.denominator + rightSide.numerator * this->denominator;
    int newDenomin = this->denominator * rightSide.denominator;

    normalize(newNumer, newDenomin);
    return {newNumer, newDenomin};
}
//operator - overloading
Rational Rational::operator- (Rational &rightSide)
{
    int newNumer = this->numerator * rightSide.denominator - rightSide.numerator * this->denominator;
    int newDenomin = this->denominator * rightSide.denominator;

    normalize(newNumer, newDenomin);
    return {newNumer, newDenomin};
}
//operator * overloading
Rational Rational::operator* (Rational &rightSide)
{
    int newNumer = this->numerator * rightSide.numerator;
    int newDenomin = this->denominator * rightSide.denominator;

    normalize(newNumer, newDenomin);
    return {newNumer, newDenomin};
}
//operator / overloading
Rational Rational::operator/ (Rational &rightSide)
{
    int newNumer = this->numerator * rightSide.denominator;
    int newDenomin = this->denominator * rightSide.numerator;

    normalize(newNumer, newDenomin);
    return {newNumer, newDenomin};
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
    //build a string for the rational number
    string str = to_string(rn.numerator) + "/" + to_string(rn.denominator);
    //put the string into the output stream
    output << str;
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
    //make sure the denominator is positive.
    if(denomin < 0) {
        numer *= -1;
        denomin *= -1;
    }
}