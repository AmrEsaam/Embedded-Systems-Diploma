/*
 * US.h
 *
 *  Created on: Sep 17, 2023
 *      Author: Amr
 */

#ifndef US_H_
#define US_H_
#include"state.h"



//define states
enum{
    US_busy
}US_State_id;

//states
STATE_DEFINE(US_Busy);

void US_Init();


#endif /* US_H_ */
