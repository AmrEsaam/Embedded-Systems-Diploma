/*
 * collision_avoidance.c
 *
 *  Created on: Sep 17, 2023
 *      Author: Amr
 */

#include"DC.h"


//global variables to the block
static int DC_Speed=0;

//state pointer (ptr to function)
void (*pDC_State)();

void DC_Init()
{
    //init PWM
    printf("\nDC Init ----------> Done");
}

void DC_Set_Speed(int s)
{
    DC_Speed=s;
    pDC_State=DC_Idle;
    printf("\nCA ----------->DC, Speed=%d \n",DC_Speed);
}

//idle state
STATE_DEFINE(DC_Idle)
{
    //state name
    DC_State_id = DC_idle;
    //state action
    //pwm to make speed =0;

    //print
    printf("\nidle state: Speed= %d \n",DC_Speed);
}

//busy state
STATE_DEFINE(DC_Busy)
{
    //state name
    DC_State_id = DC_busy;
    //state action
    //pwm to make speed =30;

    //print
    printf("\ndriving state: Speed= %d \n",DC_Speed);
    pDC_State=DC_Idle;
}

