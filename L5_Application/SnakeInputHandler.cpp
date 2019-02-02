/*
 * SnakeInputHandler.cpp
 *
 *  Created on: 13-Nov-2018
 *      Author: scsap
 */

#include "SnakeInputHandler.h"

SnakeInputHandler::SnakeInputHandler()
{
    // TODO Auto-generated constructor stub

}

SnakeInputHandler::~SnakeInputHandler()
{
    // TODO Auto-generated destructor stub
}

void SnakeInputHandler::getBoardOrientation()
{

    x_coordiante=AS.getX();
    y_coordiante=AS.getY();
    z_coordiante=AS.getZ();

    if((x_coordiante>y_coordiante)&(x_coordiante>z_coordiante)){
        boardOrientation=down;

    }
    //down
    else if((0-x_coordiante>y_coordiante)&(0-x_coordiante>z_coordiante)){
        boardOrientation=up;

    }
    //right
    else if((y_coordiante>x_coordiante )&(y_coordiante>z_coordiante)){
        boardOrientation=right;
    }
    //left
    else if((0-y_coordiante>x_coordiante )&(0-y_coordiante>z_coordiante)){
        boardOrientation=left;
    }
    else{
        boardOrientation=invalid;

    }



}


void SnakeInputHandler::getInput()
{
    getBoardOrientation();
        switch(boardOrientation){
            case up://UP
                dir=UP;
                //pY--;
                break;
            case down://DOWN
                //pY++;
                dir=DOWN;
                break;
            case left://LEFT
                //pX--;
                dir=LEFT;
                break;
            case right://RIGHT
                //pX++;
                dir=RIGHT;
                break;
            case invalid:
                //dir=STOP;
                break;
            default:
                break;
        }
}
