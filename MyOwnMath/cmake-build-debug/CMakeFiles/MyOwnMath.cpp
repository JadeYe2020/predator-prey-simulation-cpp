// MyOwnMath.cpp
// This is the implementation file
// More description goes here
// Created by JadeYe on 10/27/2021.
//
#include <iostream>
#include <conio.h>
#include "MyOwnMath.h" //programmer defined header, using quotation marks
using namespace std;

//implementation (i.e. code) for all methods
MyOwnMath::MyOwnMath() {} //default constructor
MyOwnMath::~MyOwnMath() {} //default virtual destructor

int MyOwnMath::add(int num1, int num2) {
    return num1 + num2;
}

int MyOwnMath::square(int num) {
    return num * num;
}