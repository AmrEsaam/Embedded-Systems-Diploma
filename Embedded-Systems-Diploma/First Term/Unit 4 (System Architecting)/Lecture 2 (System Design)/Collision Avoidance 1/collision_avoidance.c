/*
 * collision_avoidance.c
 *
 *  Created on: Sep 17, 2023
 *      Author: Amr
 */

#include"collision_avoidance.h"


//global variables to the block
static int CA_Speed=0;
static int CA_Distance=0;
static int CA_Threshold=50;

//state pointer (ptr to function)
void (*pCA_State)();

//get distance function prototype
int US_GET_DISTANCE(int l, int r, int count);

//waiting state
STATE_DEFINE(CA_Waiting)
{
    //state name
    CA_State_id = CA_waiting;
    //state action
    CA_Speed=0;
    //DC_SET_SPEED(CA_Speed);
    //distance check
    CA_Distance=US_GET_DISTANCE(45,55,1);
    //event check
    (CA_Distance <= CA_Threshold)? (pCA_State=STATE(CA_Waiting)) : (pCA_State=STATE(CA_Driving));
    //print
    printf("\nWaiting state: Distatnce= %d ,Speed= %d \n",CA_Distance,CA_Speed);
}

//driving state
STATE_DEFINE(CA_Driving)
{
    //state name
    CA_State_id = CA_driving;
    //state action
    CA_Speed=30;
    //DC_SET_SPEED(CA_Speed);

    //event check
    //distance check
    CA_Distance=US_GET_DISTANCE(45,55,1);
    (CA_Distance <= CA_Threshold)? (pCA_State=STATE(CA_Waiting)) : (pCA_State=STATE(CA_Driving));
    //print
    printf("\ndriving state: Distatnce= %d ,Speed= %d \n",CA_Distance,CA_Speed);
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