/*
 * Game.h
 *
 *  Created on: 12-Nov-2018
 *      Author: scsap
 */

#ifndef GAME_H_
#define GAME_H_
#include <stdint.h>
#include <stdlib.h>

//#include "Objects.h"
class Game {
public:
    Game(uint8_t boardX,uint8_t boardY);
    //Dimensions of GAME DISPLAY

    uint8_t x;
    uint8_t y;
    //Properties of Game:
    uint8_t totalObj;
    uint8_t totalObjCaught;
    uint8_t score;
    int8_t level;
    //Array of Objects in Game
    //Objects arrOfObjs[30];//Max 30 Objects
    bool isGameOver; //:: True-GameOver| False-Play


    virtual ~Game();
};

#endif /* GAME_H_ */
