/*
 * SnakeDisplayHandler.h
 *
 *  Created on: 13-Nov-2018
 *      Author: scsap
 */

#ifndef SNAKEDISPLAYHANDLER_H_
#define SNAKEDISPLAYHANDLER_H_
#include "RGBmatrixPanel.h"
#include "Fruit.h"
#include "Snake.h"
class SnakeDisplayHandler {
public:
    SnakeDisplayHandler();
    void displayFense(RGBmatrixPanel& matrix);
    void displaySnake(Snake& snakeObj,RGBmatrixPanel& matrix);
    void displayFruit(Fruit& fruitObj,RGBmatrixPanel& matrix);
    void displayTail(Snake& snakeObj,RGBmatrixPanel& matrix);
    void calldisplayDaddy(Fruit& fruitObj,Snake& snakeObj,RGBmatrixPanel& matrix);
    virtual ~SnakeDisplayHandler();
};

#endif /* SNAKEDISPLAYHANDLER_H_ */
