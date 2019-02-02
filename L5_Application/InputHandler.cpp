/*
 * InputHandler.cpp
 *
 *  Created on: 12-Nov-2018
 *      Author: scsap
 */

#include <InputHandler.h>

InputHandler::InputHandler(Basket& bskObj)
{
    dir=STOP;
    y_coordiante=y_coordiante=z_coordiante=0;
    py_coordiante=py_coordiante=pz_coordiante=0;
    // TODO Auto-generated constructor stub

}



void InputHandler::getBoardOrientation(Basket& bskObj)
{
    //printf("getBoardOrientation: \n");
    x_coordiante=AS.getX();
    y_coordiante=AS.getY();
    z_coordiante=AS.getZ();
    //printf("getBoardOrientation: testing:%d \n",(y_coordiante));



}



//left
//if ((y_coordiante>y_coordiante )&(y_coordiante>z_coordiante)){
/*if (y_coordiante<py_coordiante  && abs(y_coordiante)>threshold){
        printf("getBoardOrientation: left:%d \n",(y_coordiante));
        boardOrientation=left;
        py_coordiante=y_coordiante;
        px_coordiante=x_coordiante;
        pz_coordiante=z_coordiante;

    }
    //right
    else if(y_coordiante>py_coordiante && abs(y_coordiante)>threshold){
        printf("getBoardOrientation: right:%d \n",(y_coordiante));
        boardOrientation=right;
       // py_coordiante=y_coordiante;
        py_coordiante=y_coordiante;
        px_coordiante=x_coordiante;
        pz_coordiante=z_coordiante;


    }


    else{

        boardOrientation=invalid;
        py_coordiante=y_coordiante;
        printf("getBoardOrientation: invalid \n");
        //uart0_puts("Inside boardOrientation_invalid \n");
    }

 */

}






void InputHandler::getInput(Basket& bskObj)
{

   // getBoardOrientation(bskObj);
    //uart0_puts("Inside getInput \n");

    // printf("getInput:direction-%i,boarOrientaion-%i \n",(int)dir,y_coordiante);

    //--------------INPUT LOGIC--------------------
    switch(boardOrientation){
        case right:
            dir=RIGHT;
            //printf("dir: RIGHT \n");
            break;
        case left:
            dir=LEFT;
            //printf("dir: LEFT \n");
            break;

        case invalid:
        default:
            dir=STOP;
            //printf("dir: STOP \n");
            break;

            //--------------INPUT LOGIC ENDS--------------------


    }
}

void InputHandler::callInputDaddy(Basket& bskObj)
{
    // printf("inputDaddy: \n");

    //getInput(bskObj) ;
    getBoardOrientation(bskObj);
}



InputHandler::~InputHandler()
{
    // TODO Auto-generated destructor stub
}

