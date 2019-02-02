/*
 * SnakeDisplayHandler.cpp
 *
 *  Created on: 13-Nov-2018
 *      Author: scsap
 */

#include "SnakeDisplayHandler.h"

SnakeDisplayHandler::SnakeDisplayHandler()
{
    // TODO Auto-generated constructor stub

}

void SnakeDisplayHandler::displayFense(RGBmatrixPanel& matrix)
{
    matrix.drawRect(0, 0, 32, 32, matrix.Color333(7, 0, 7));//Game Arena
}

void SnakeDisplayHandler::displaySnake(Snake& snakeObj, RGBmatrixPanel& matrix)
{

    matrix.drawLine(snakeObj.x+1, snakeObj.y, snakeObj.x-1, snakeObj.y, matrix.Color333(0, 0, 7));
    matrix.drawLine(snakeObj.x, snakeObj.y-1, snakeObj.x, snakeObj.y+1, matrix.Color333(0, 0, 7));
    matrix.drawPixel(snakeObj.x, snakeObj.y, matrix.Color333(7, 0, 0));
    //matrix.drawLine(snakeObj.x, snakeObj.y, snakeObj.x, snakeObj.y+2, matrix.Color333(0, 0, 7));
}

void SnakeDisplayHandler::displayFruit(Fruit& fruitObj, RGBmatrixPanel& matrix)
{
    matrix.drawPixel(fruitObj.x, fruitObj.y, matrix.Color333(7, 7, 0));
 /*   matrix.drawPixel(fruitObj.x, fruitObj.y+1, matrix.Color333(7, 7, 0));
    matrix.drawPixel(fruitObj.x-1, fruitObj.y, matrix.Color333(7, 7, 0));
    matrix.drawPixel(fruitObj.x-1, fruitObj.y+1, matrix.Color333(7, 7, 0));
*/
}

void SnakeDisplayHandler::calldisplayDaddy(Fruit& fruitObj, Snake& snakeObj, RGBmatrixPanel& matrix)
{
    matrix.fillScreen(0);
    displayFense(matrix);
    displayTail(snakeObj,matrix);
    displaySnake(snakeObj,matrix);
    displayFruit(fruitObj,matrix);

    matrix.swapBuffers(false);

}

void SnakeDisplayHandler::displayTail(Snake& snakeObj,RGBmatrixPanel& matrix)
{
    for(int i=0;i<snakeObj.ntail;i++){
      //  printf("in here \n %i,%i:,%i,%i",snakeObj.tailX[i],snakeObj.tailY[i],snakeObj.x,snakeObj.y);
        matrix.drawPixel(snakeObj.tailX[i],snakeObj.tailY[i],matrix.Color333(0,7,7));
    }
}

SnakeDisplayHandler::~SnakeDisplayHandler()
{
    // TODO Auto-generated destructor stub
}

