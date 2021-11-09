// Bicycle.h - header file for Bicycle class
// Created by JadeYe on 11/9/2021.
//

#ifndef POLYVEHICLES_BICYCLE_H
#define POLYVEHICLES_BICYCLE_H

#include <string>
#include "Vehicle.h"

class Bicycle : public Vehicle //inherits
{
public:
    Bicycle(void);
    virtual ~Bicycle(void);
    virtual string BlowHorn();
};


#endif //POLYVEHICLES_BICYCLE_H
