/*
 * Snake.cpp
 *
 *  Created on: 12-Nov-2018
 *      Author: scsap
 */

#include "Snake.h"

Snake::Snake(Game& gameObj)
{
   x=(gameObj.x-1)/2; // TODO Auto-generated constructor stub
   y=(gameObj.y-1)/2;
   ntail=0;

}

Snake::~Snake()
{
    // TODO Auto-generated destructor stub
}

