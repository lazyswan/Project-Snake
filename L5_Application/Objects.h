/*
 * Objects.h
 *
 *  Created on: 12-Nov-2018
 *      Author: scsap
 */

#ifndef OBJECTS_H_
#define OBJECTS_H_
#include <stdint.h>
#include <stdlib.h>
#include <time.h>
#include "Game.h"
class Objects {
public:


    bool isAlive;// True::Object alive|False:: Object Dead
    //Position of Falling Objects
    int16_t x;
    int16_t y;
    //Dimensions of Falling Objects

    int16_t height;
    int16_t widht;

    //Color of Object
    uint8_t r;
    uint8_t g;
    uint8_t b;

    //Properties of Falling Objects
    int8_t speed;       //Speed :: 1X|2X|3X
    int8_t magicalPow;  //Power :: 1-Normal|2-Evil_destroy Player|3-Good
    Objects();
    Objects(bool validObjs);







    virtual ~Objects();
};

#endif /* OBJECTS_H_ */
