/*
 * Basket.h
 *
 *  Created on: 12-Nov-2018
 *      Author: scsap
 */

#ifndef BASKET_H_
#define BASKET_H_
#include <stdint.h>
#include <stdlib.h>
#include "Game.h"
#include "Water.h"
class Basket {
public:
    Basket(Game &gameObj,Water &waterObj);
    bool isBasketalive; //::true-basket visible | false-basket invisible
    //Position of Basket
    int8_t x;
    int8_t y;
    //properties of Basket
    int8_t offsetFrmCenter; // length of Basket= offset+....x....-offset
    int8_t speed; //Speed of Basket :: sensitivity |1X|2X|3X :: changes based on Input;
    //Basket Color
    uint8_t r;
    uint8_t g;
    uint8_t b;

    virtual ~Basket();
};

#endif /* BASKET_H_ */
