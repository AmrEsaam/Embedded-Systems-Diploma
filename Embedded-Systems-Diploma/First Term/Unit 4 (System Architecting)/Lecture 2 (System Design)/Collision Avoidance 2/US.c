/*
 * collision_avoidance.c
 *
 *  Created on: Sep 17, 2023
 *      Author: Amr
 */

#include"US.h"


//global variables to the block
static int US_Distance=0;

//state pointer (ptr to function)
void (*pUS_State)();

//get distance function prototype
int US_GET_DISTANCE(int l, int r, int count);

void US_Init()
{
    //init US Driver
    printf("\nUS Init ----------> Done");
}

//busy state
STATE_DEFINE(US_Busy)
{
    //state name
    US_State_id = US_busy;
    //state action
    US_Distance=US_GET_DISTANCE(45,55,1);
    //event check --> same state
    //print
    printf("\nWaiting state: Distatnce= %d \n",US_Distance);
    US_Set_Distance(US_Distance);
    pUS_State=US_Busy;
}


int US_GET_DISTANCE(int l, int r, int count)
{
    int i=0;
    for(i=0;i<count;i++)
    {
        int rand_num = (rand() % (r-l+1))+45;
        return rand_num;
    }
}
