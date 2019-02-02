/*
 * DisplayHandler.cpp
 *
 *  Created on: 12-Nov-2018
 *      Author: scsap
 */

#include <DisplayHandler.h>

DisplayHandler::DisplayHandler()
{
    // TODO Auto-generated constructor stub

}

void DisplayHandler::displayWater(Water& waterObj,RGBmatrixPanel& matrix)
{

    matrix.fillRect(0,0,32,waterObj.waterLevel+1,matrix.Color333(waterObj.r,waterObj.g,waterObj.b));

}

void DisplayHandler::displayBasket(Basket& bskObj,RGBmatrixPanel& matrix)
{
    //uart0_puts("Inside drawBasket \n");

    matrix.drawLine((bskObj.x-bskObj.offsetFrmCenter),bskObj.y,(bskObj.x+bskObj.offsetFrmCenter),bskObj.y,matrix.Color333(bskObj.r,bskObj.g,bskObj.b));

    matrix.drawPixel(bskObj.x+bskObj.offsetFrmCenter,bskObj.y+1,matrix.Color333(bskObj.r,bskObj.g,bskObj.b));
    matrix.drawPixel(bskObj.x-bskObj.offsetFrmCenter,bskObj.y+1,matrix.Color333(bskObj.r,bskObj.g,bskObj.b));


    matrix.drawPixel(bskObj.x+bskObj.offsetFrmCenter,bskObj.y+2,matrix.Color333(bskObj.r,bskObj.g,bskObj.b));
    matrix.drawPixel(bskObj.x-bskObj.offsetFrmCenter,bskObj.y+2,matrix.Color333(bskObj.r,bskObj.g,bskObj.b));



}

void DisplayHandler::displayObject(Objects (&obj)[30],Game& gameObj,RGBmatrixPanel& matrix)
{

    for(int i=0;i<30;i++){
        if(obj[i].isAlive){//IfObject is Alive Then Display it
            matrix.fillRect(obj[i].x,obj[i].y,obj[i].widht,obj[i].height,
                    matrix.Color333(obj[i].r,obj[i].g,obj[i].b));
            //matrix.drawPixel(obj[i].x,obj[i].y,matrix.Color333(7,0,0));//testing Purpose
        }
    }

}

void DisplayHandler::refreshScreen(RGBmatrixPanel& matrix)
{
    matrix.fillScreen(0);
}

//This Method Call All the DisplayFunctions
void DisplayHandler::callDisplayDaddy(Water& waterObj,Basket& bskObj,Objects (&obj)[30],Game& gameObj,RGBmatrixPanel& matrix)
{
    refreshScreen(matrix);
    displayWater(waterObj,matrix);
    displayBasket(bskObj,matrix);
   // displayObject(obj,gameObj,matrix);

    matrix.swapBuffers(false);
}

DisplayHandler::~DisplayHandler()
{
    // TODO Auto-generated destructor stub
}

