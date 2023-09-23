/*
 * main.c
 *
 *  Created on: Sep 17, 2023
 *      Author: Amr
 */


#include"collision_avoidance.h"
//state pointer (ptr to function)
extern void (*pCA_State)();

void setup()
{
    //init all drivers
    //init IRQ
    //init US & DC_MOTOR
    //init block
    //Set state ptr for each block
    pCA_State=STATE(CA_Waiting);
}

int main()
{
    int volatile i=0;
    setup();
    
    while(1)
    {
        //call state for each block
        pCA_State();
        for(i=0;i<1000000000;i++);
    }


    return 0;
}