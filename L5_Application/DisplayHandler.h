/*
 * DisplayHandler.h
 *
 *  Created on: 12-Nov-2018
 *      Author: scsap
 */

#ifndef DISPLAYHANDLER_H_
#define DISPLAYHANDLER_H_
#include "Water.h"
#include "Basket.h"
#include "Objects.h"
#include "RGBmatrixPanel.h"
class DisplayHandler {
public:
    DisplayHandler();
    void callDisplayDaddy(Water& waterObj,Basket& bskObj,Objects (&obj)[30],Game& gameObj,RGBmatrixPanel& matrix);
    void displayWater(Water& waterObj,RGBmatrixPanel& matrix);
    void displayBasket(Basket& bskObj,RGBmatrixPanel& matrix);
    void displayObject(Objects (&obj)[30],Game& gameObj,RGBmatrixPanel& matrix);
    void refreshScreen(RGBmatrixPanel& matrix);
    virtual ~DisplayHandler();
};

#endif /* DISPLAYHANDLER_H_ */
