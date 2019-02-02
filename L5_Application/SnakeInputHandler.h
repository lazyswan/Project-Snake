/*
 * SnakeInputHandler.h
 *
 *  Created on: 13-Nov-2018
 *      Author: scsap
 */

#ifndef SNAKEINPUTHANDLER_H_
#define SNAKEINPUTHANDLER_H_
#include <stdint.h>
#include <stdio.h>
#include "i2c2_device.hpp"
#include "Basket.h"
#include "Game.h"
#include "Snake.h"
#include "acceleration_sensor.hpp"
#define AS Acceleration_Sensor::getInstance()




 // namespace snakeIH

class SnakeInputHandler {
    enum  eorientation{
        invalid=0,
        up,
        down,
        left,
        right
    };

    enum  eDirections{
        STOP=0,
        UP,
        DOWN,
        LEFT,
        RIGHT
    };
public:
    SnakeInputHandler();
    virtual ~SnakeInputHandler();
    int16_t x_coordiante,y_coordiante,z_coordiante;
    eorientation boardOrientation;
    eDirections dir;
    //void callInputDaddy(Basket& bskObj);//Calls all the method
    void getBoardOrientation();
    void getInput();


};

#endif /* SNAKEINPUTHANDLER_H_ */

