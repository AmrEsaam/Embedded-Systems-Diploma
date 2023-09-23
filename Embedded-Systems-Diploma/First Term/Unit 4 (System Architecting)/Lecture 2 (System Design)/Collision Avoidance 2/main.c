/*
 * main.c
 *
 *  Created on: Sep 17, 2023
 *      Author: Amr
 */


#include"collision_avoidance.h"
#include"US.h"
#include"DC.h"
//state pointer (ptr to function)
extern void (*pCA_State)();
extern void (*pUS_State)();
extern void (*pDC_State)();

void setup()
{
    //init all drivers
    //init IRQ
    //init US & DC_MOTOR
    //init block
    US_Init();
    DC_Init();
    //Set state ptr for each block
    pCA_State=STATE(CA_Waiting);
    pUS_State=STATE(US_Busy);
    pDC_State=STATE(DC_Idle);
}

int main()
{
    int volatile i=0;
    setup();
    
    while(1)
    {
        //call state for each block
        pUS_State();
        pCA_State();
        pDC_State();
        for(i=0;i<1000000000;i++);
    }


    return 0;
}