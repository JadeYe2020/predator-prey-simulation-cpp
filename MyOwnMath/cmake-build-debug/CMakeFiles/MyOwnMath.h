// MyOwnMath header file
// This is the interface for the MyOwnMath class
// It contains two methods square() and int() returning ints
// Created by JadeYe on 10/27/2021.
//

#ifndef MYOWNMATH_MYOWNMATH_H //if not defined
#define MYOWNMATH_MYOWNMATH_H //then define, otherwise, don't do
using namespace std;

class MyOwnMath
{
    public:
        //default constructor
        MyOwnMath(void);
        virtual ~MyOwnMath(void); //virtual destructor
        int square(int);
        int add(int, int);
}; //end class


#endif //MYOWNMATH_MYOWNMATH_H
