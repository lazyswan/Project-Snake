/*
 * Objects.cpp
 *
 *  Created on: 12-Nov-2018
 *      Author: scsap
 */

#include <Objects.h>


Objects::Objects()
{

    isAlive=false;// True::Object alive|False:: Object Dead
        //Position of Falling Objects


}

Objects::~Objects()
{
    // TODO Auto-generated destructor stub
}

Objects::Objects(bool validObjs)
{
    isAlive=true;
    x=(rand()%26)+3;// Range of X-0 to 31 basket takes 2 px so netRange for object is 3 to 28
            y=32-1;//Objects should Fall from Top
            //Dimensions of Falling Objects

            height=(rand()%2)+2;// Height can only be 2 or 3
            widht=(rand()%2)+2;// Height can only be 2 or 3

            //Color of Object
            r=0;
            g=0;
            b=0;

            //Properties of Falling Objects
            speed=1;       //Speed :: 1X|2X|3X
            magicalPow=(rand()%3)+1;  //Power :: 1-Normal|3-Evil_destroy Player|2-Good

}
