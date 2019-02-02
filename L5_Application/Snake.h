/*
 * Snake.h
 *
 *  Created on: 12-Nov-2018
 *      Author: scsap
 */

#ifndef SNAKE_H_
#define SNAKE_H_
#include "Game.h"
class Snake {
public:
    Snake(Game& gameObj);
    int16_t x,y;
    int16_t tailX[50];//tail of snake
    int16_t tailY[50];
    int16_t prevX,prevY;
    int16_t ntail;

    virtual ~Snake();
};

#endif /* SNAKE_H_ */
