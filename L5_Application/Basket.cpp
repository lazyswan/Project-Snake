/*
 * Basket.cpp
 *
 *  Created on: 12-Nov-2018
 *      Author: scsap
 */

#include <Basket.h>

Basket::Basket(Game &gameObj,Water &waterObj)
{
    isBasketalive=true; //::true-basket visible | false-basket invisible
       //Position of Basket
       x=gameObj.x/2;
       y=waterObj.waterLevel+1;//Basket Appear 1 Level Above Water;
       //properties of Basket
      offsetFrmCenter=2; // length of Basket= offset+....x....-offset
      speed=1; //Speed of Basket :: sensitivity |1X|2X|3X :: changes based on Input;
       //Basket Color
       r=7;
       g=0;
       b=7;

}

Basket::~Basket()
{
    // TODO Auto-generated destructor stub
}

