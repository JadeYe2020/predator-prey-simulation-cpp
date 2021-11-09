// Boat.h - header file for Boat class
// Created by JadeYe on 11/9/2021.
//

#ifndef POLYVEHICLES_BOAT_H
#define POLYVEHICLES_BOAT_H

#include <string>
#include "Vehicle.h"

class Boat : public Vehicle //inherits
{
    public:
        Boat(void);
        virtual ~Boat(void);
        virtual string BlowHorn();
};


#endif //POLYVEHICLES_BOAT_H
