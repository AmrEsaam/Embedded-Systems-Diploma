/*
 * DC.h
 *
 *  Created on: Sep 17, 2023
 *      Author: Amr
 */

#ifndef DC_H_
#define DC_H_
#include"state.h"



//define states
enum{
    DC_idle,
    DC_busy
}DC_State_id;

//states
STATE_DEFINE(DC_Idle);
STATE_DEFINE(DC_Busy);

void DC_Init();




#endif /* DC_H_ */
