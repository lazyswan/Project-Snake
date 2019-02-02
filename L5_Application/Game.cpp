/*
 * Game.cpp
 *
 *  Created on: 12-Nov-2018
 *      Author: scsap
 */

#include <Game.h>

Game::Game(uint8_t boardX,uint8_t boardY)
{
    //Dimensions of GAME DISPLAY

         x=boardX;
         y=boardX;
        //Properties of Game:
         totalObj=0;
         totalObjCaught=0;
         score=0;
         level=1;
         isGameOver=false; //:: True-GameOver| False-Play


}

Game::~Game()
{
    // TODO Auto-generated destructor stub
}

