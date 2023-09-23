/*
 * collision_avoidance.h
 *
 *  Created on: Sep 17, 2023
 *      Author: Amr
 */

#ifndef COLLISION_AVOIDANCE_H_
#define COLLISION_AVOIDANCE_H_
#include"state.h"



//define states
enum{
    CA_waiting,
    CA_driving
}CA_State_id;

//states
STATE_DEFINE(CA_Waiting);
STATE_DEFINE(CA_Driving);




#endif /* COLLISION_AVOIDANCE_H_ */
