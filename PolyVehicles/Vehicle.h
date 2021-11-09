//Vehicle.h - header file for Vehicle class
// Created by JadeYe on 11/9/2021.
//

#ifndef POLYVEHICLES_VEHICLE_H
#define POLYVEHICLES_VEHICLE_H
#include <string>
using namespace std;

class Vehicle {
    public:
        Vehicle(void); //constructor
        virtual ~Vehicle(void); //virtual destructor
    //    string BlowHorn(); //regular
        virtual string BlowHorn(); //virtual for late binding
    //    virtual string BlowHorn()= 0; //pure virtual i.e. abstract
};


#endif //POLYVEHICLES_VEHICLE_H
