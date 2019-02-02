/*
 * SnakeLogicHandler.cpp
 *
 *  Created on: 13-Nov-2018
 *      Author: scsap
 */

#include "SnakeLogicHandler.h"

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
SnakeLogicHandler::SnakeLogicHandler()
{
    // TODO Auto-generated constructor stub

}

void SnakeLogicHandler::moveSnake(SnakeInputHandler& sIpHadle,Snake& snakeObj)
{
    switch(sIpHadle.dir){
        case UP:
            snakeObj.y++;
            printf("Up \n");
            break;

        case DOWN:
            snakeObj.y--;
            printf("Down \n");
            break;
        case LEFT:
            snakeObj.x++;
            printf("Left \n");
            break;
        case RIGHT:
            snakeObj.x--;
            printf("RIGHT \n");
            break;
        default:
            break;
    }
}

void SnakeLogicHandler::wallPassingLogic(Snake& snakeObj,Game gameObj)
{
    if(snakeObj.x>=gameObj.x-1){
        snakeObj.x=1;
    }
    else if(snakeObj.x<1){
        snakeObj.x=gameObj.x-1;
    }
    else if(snakeObj.y>gameObj.y-1){
        snakeObj.y=1;
    }
    else if(snakeObj.y<1){
        snakeObj.y=gameObj.y-1;
    }
}

void SnakeLogicHandler::fruitEatingLogic(Fruit& fruitObj, Snake& snakeObj,Game& gameObj)
{
    if(fruitObj.x>=snakeObj.x-2 && fruitObj.x<=snakeObj.x+2 &&  fruitObj.y<=snakeObj.y+2 && fruitObj.y>=snakeObj.y-2){
        fruitObj.x=(rand()%gameObj.x-2)+1;
        fruitObj.y=(rand()%gameObj.y-2)+1;
        gameObj.score++;
        snakeObj.ntail++;//Tail of Snake
      }
}

void SnakeLogicHandler::callLogicHandlerDaddy(SnakeInputHandler& sIpHadle, Snake& snakeObj, Game& gameObj, Fruit& fruitObj)
{
    moveSnake(sIpHadle,snakeObj);
    wallPassingLogic(snakeObj,gameObj);
    fruitEatingLogic(fruitObj,snakeObj,gameObj);
    tailLogic(snakeObj);

}

void SnakeLogicHandler::tailLogic(Snake& snakeObj)
{
    snakeObj.prevX=snakeObj.tailX[0];
    snakeObj.prevY=snakeObj.tailY[0];
      int16_t prev2X,prev2Y;

      snakeObj.tailX[0]=snakeObj.x;
      snakeObj.tailY[0]=snakeObj.y;
      for(int16_t i=1;i<=snakeObj.ntail;i++){
        prev2X=snakeObj.tailX[i];
        prev2Y=snakeObj.tailY[i];

        snakeObj.tailX[i]=snakeObj.prevX;
        snakeObj.tailY[i]=snakeObj.prevY;
        snakeObj.prevX=prev2X;
        snakeObj.prevY=prev2Y;

}
}

SnakeLogicHandler::~SnakeLogicHandler()
{
    // TODO Auto-generated destructor stub
}

