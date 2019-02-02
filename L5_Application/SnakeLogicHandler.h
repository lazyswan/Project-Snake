/*
 * SnakeLogicHandler.h
 *
 *  Created on: 13-Nov-2018
 *      Author: scsap
 */

#ifndef SNAKELOGICHANDLER_H_
#define SNAKELOGICHANDLER_H_
#include "SnakeInputHandler.h"
#include "Snake.h"
#include "Fruit.h"
class SnakeLogicHandler {
public:
    SnakeLogicHandler();
    void moveSnake(SnakeInputHandler & sIpHadle,Snake& snakeObj);
    void wallPassingLogic(Snake& snakeObj,Game gameObj);
    void fruitEatingLogic(Fruit& fruitObj,Snake& snakeObj,Game& gameObj);
    void tailLogic(Snake& snakeObj);
    void callLogicHandlerDaddy(SnakeInputHandler& sIpHadle,Snake& snakeObj,Game& gameObj,Fruit& fruitObj);
    virtual ~SnakeLogicHandler();
};

#endif /* SNAKELOGICHANDLER_H_ */
