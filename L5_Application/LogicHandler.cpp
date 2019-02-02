/*
 * LogicHandler.cpp
 *
 *  Created on: 12-Nov-2018
 *      Author: scsap
 */

#include <LogicHandler.h>

LogicHandler::LogicHandler()
{
    maxOnscreenObj=0;

}

void LogicHandler::slideBasket(InputHandler& ipObj,Basket& bskObj,Game & gameObj)
{
    //Function Slides the Basket and Logic to stop the sliding once it Reaches the edge of LED board.
   switch(ipObj.dir){
        case LEFT:
            bskObj.x+=bskObj.speed;
            ipObj.dir=STOP;
            break;
        case RIGHT:
            bskObj.x-=bskObj.speed;
            ipObj.dir=STOP;
            break;
        default:
            ipObj.dir=STOP;
            break;

    }

    stopSlidingAtEdge(bskObj,gameObj);

}

void LogicHandler::stopSlidingAtEdge(Basket& bskObj,Game & gameObj)
{

    //------Stop Movement when Basket Reaches Boarder--------------
    if(bskObj.x+bskObj.offsetFrmCenter>gameObj.x-1){
        bskObj.x=gameObj.x-bskObj.offsetFrmCenter-1;
    }
    else if(bskObj.x-bskObj.offsetFrmCenter<0){
        bskObj.x=bskObj.offsetFrmCenter;
    }



}

void LogicHandler::checkIfGameOver(Game& gameObj, Basket& bskObj,Water& waterObj)
{
    if(waterObj.waterLevel>gameObj.y-5||(!bskObj.isBasketalive)){
        gameObj.isGameOver=true;

        }


}

void LogicHandler::updateBskHeightAsPerWaterLevel(Basket& bskObj,Water& waterObj)
{
    bskObj.y=waterObj.waterLevel+1;
}

void LogicHandler::objectFreeFallLogic(Objects(&obj)[30])
{
    for(int i=0;i<30;i++){
        if(obj[i].isAlive){
            obj[i].y-=obj[i].speed;
        }
    }

}

void LogicHandler::genearateRandomObjects(Game & gameObj)
{
    // objArrPtr=new Objects[30,Objects(gameObj)];

    //int noOfObj=(rand()%5)+1;//Objects between 1-5 are generated at a time;
    if(maxOnscreenObj<5){
        Objects obj_temp(true);

        switch(obj_temp.magicalPow){
            case 1://normal
                obj_temp.r=7;
                obj_temp.g=7;
                obj_temp.b=0;
                break;
            case 2://magical
                obj_temp.r=7;
                obj_temp.g=7;
                obj_temp.b=7;
                break;
            case 3://evil
                obj_temp.r=7;
                obj_temp.g=0;
                obj_temp.b=0;
                break;

        }
        objArr[(gameObj.totalObj++)%30]=obj_temp;//Maximum 30 Objects can be there in Game;TotalObjs Keeps Count of generated Objs

        maxOnscreenObj++;
    }

}

void LogicHandler::checkifCaughtMiss(Objects (&obj)[30],Basket& bskObj,Game& gameObj,Water& waterObj  )
{
    for(int i=0;i<30;i++){
        if(obj[i].isAlive){
            if(obj[i].x<=bskObj.x+bskObj.offsetFrmCenter
                    && obj[i].x>=bskObj.x-bskObj.offsetFrmCenter
                    && obj[i].y==bskObj.y+1)
            {
                //object Caught

                printf("score:%i \n",gameObj.score);
                obj[i].isAlive=false;//make the object dead;

                //change the Color of basket as per object caught
                bskObj.r=obj[i].r;
                bskObj.g=obj[i].g;
                bskObj.b=obj[i].b;

                //check if Object's Magical Power
                switch(obj[i].magicalPow){
                    case 1:
                        gameObj.score++;
                        break;
                    case 2:
                        //Basket Size Increase Code;
                        break;
                    case 3://Evil Egg :: Game Over
                       // gameObj.isGameOver=true;
                        break;

                }

                maxOnscreenObj--;
                //Check for Magical Power and all
            }

            else if(obj[i].y<=waterObj.waterLevel){
                // Object Miss
                obj[i].isAlive=false;//Make object Dead
                waterObj.waterThreshold++;
                //Change the color of Basket back to Default:
                bskObj.r=7;
                bskObj.g=0;
                bskObj.b=7;
                //Decrease the Water Level if Red Object is miss:
                if(obj[i].magicalPow==3 && waterObj.waterLevel>2){
                    waterObj.waterLevel--;
                }
                //Increase the Water Level after 3 objects are sink ;
                if(waterObj.waterThreshold>3){
                    waterObj.waterLevel++;
                    waterObj.waterThreshold=0;
                }

                maxOnscreenObj--;
            }
        }

    }

}

LogicHandler::~LogicHandler()
{
    // TODO Auto-generated destructor stub
}

void LogicHandler::callLogicDaddy(InputHandler& ipObj, Basket& bskObj, Game& gameObj, Water& waterObj,Objects(&obj)[30])
{
    slideBasket(ipObj,bskObj,gameObj);//working Tested
    stopSlidingAtEdge(bskObj,gameObj);//Working Tested
    //checkIfGameOver(gameObj,bskObj,waterObj);//working Tested
    updateBskHeightAsPerWaterLevel(bskObj,waterObj);//Not Fully Implemented :: waterLevelReducation Logic Remaining
    genearateRandomObjects(gameObj);
    objectFreeFallLogic(obj);
    checkifCaughtMiss(obj,bskObj,gameObj,waterObj);
}
