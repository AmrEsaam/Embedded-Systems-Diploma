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

void US_Set_Distance(int d)
{
    CA_Distance=d;
    (CA_Distance <= CA_Threshold)? (pCA_State=STATE(CA_Waiting)) : (pCA_State=STATE(CA_Driving));
    printf("\nUS ----------->CA, Distance=%d \n",CA_Distance);
}

//waiting state
STATE_DEFINE(CA_Waiting)
{
    //state name
    CA_State_id = CA_waiting;
    printf("\nwaiting state: Distatnce= %d ,Speed= %d \n",CA_Distance,CA_Speed);
    //state action
    CA_Speed=0;
    DC_Set_Speed(CA_Speed);
}

//driving state
STATE_DEFINE(CA_Driving)
{
    //state name
    CA_State_id = CA_driving;
    printf("\ndriving state: Distatnce= %d ,Speed= %d \n",CA_Distance,CA_Speed);
    //state action
    CA_Speed=30;
    DC_Set_Speed(CA_Speed);
}

