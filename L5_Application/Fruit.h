/*
 * Fruit.h
 *
 *  Created on: 12-Nov-2018
 *      Author: scsap
 */

#ifndef FRUIT_H_
#define FRUIT_H_
#include <stdint.h>
#include <stdio.h>
#include  <time.h>
#include <stdlib.h>
class Fruit {
public:
    Fruit();
    int16_t x,y;
    virtual ~Fruit();
};

#endif /* FRUIT_H_ */
