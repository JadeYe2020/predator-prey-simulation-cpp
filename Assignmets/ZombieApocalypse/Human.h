// Reference: assignment supporting docs
// Created by JadeYe on 11/28/2021.
//

#ifndef ZOMBIEAPOCALYPSE_HUMAN_H
#define ZOMBIEAPOCALYPSE_HUMAN_H

#include "Organism.h"

class Human : public Organism
{
public:
    Human();
    Human( City *city, int width, int height );
    virtual ~Human();

    void move();
};

#endif //ZOMBIEAPOCALYPSE_HUMAN_H
