/*
 * state.h
 *
 *  Created on: Sep 17, 2023
 *      Author: Amr
 */

#ifndef STATE_H_
#define STATE_H_
#include<stdio.h>
#include<stdlib.h>

//state function definition generator
#define STATE_DEFINE(_StateFunc_) void _StateFunc_()
#define STATE(_StateFunc_) _StateFunc_

//States Connections
void US_Set_Distance(int d);
void DC_Set_Speed(int s);

#endif /* STATE_H_ */
