//Pointer Basics

#include <iostream>

#include <string>
#include <conio.h>
using namespace std;

int main() {
    //pointer terminology
    //use * the declarative operator
    //also use the * dereference operator
    //use & as the "address of" operator
    //user the -> s the "points to" operator

    string phrase1 = "I woz here.";
    string phrase2 = " Here I woz.";
    string phrase3 = " Woz I here?";
    string phrase4 = " Yes, I woz!";

    //regular use of variable names
    cout << phrase1 + phrase2 + phrase3 + phrase4 << endl;

    //use of address of operator
    cout << &phrase1 << endl;
//    cout << *phrase1 << endl;

    string *p1; //Declare a pointer to string using declare operator.
    string *p2;
    string *p3;

    p1 = &phrase1;  //Assign address to pointer.
    p2 = &phrase2;
    p3 = &phrase3;

    string *p4 = &phrase4;  //Declare and assign at the same time.

    cout << p1 << endl; //an address inside p1 (i.e. the pointer's value)
    cout << *p1 + *p2 + *p3 + *p4 << endl;  //shows epic poem
    cout << *p1 << endl;    //what is pointed to
    cout << p1 << endl; //value of p1
    cout << &p1 << endl;    //address of pointer variable itself

//    string x = p1 + p2; //adding addresses is an error.
    string  y = *p1 + *p2;  //concat two strings
    cout << p1 << endl;
    cout << p2 << endl;
    p2 = p1;    // assign address in 1 to 2 - both point to the same thing now
    cout << p1 << endl;
    cout << p2 << endl;

    //how to make a "nameless" variable (aka unnamed)
    int *pNless;    //declare pointer
    pNless = new int;   //Reserves memory
    *pNless = 3;    //Assign int value to unnamed memory location
    cout << *pNless << endl;    //displays 3

    int *pN2 = new int(7);  //Declare and assign value to nameless

    return 0;
}
