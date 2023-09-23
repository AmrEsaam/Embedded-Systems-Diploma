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
void send_pressure_val(int pval);
void set_alarm_on();
void set_alarm_off();
int high_pressure_detected();

#endif /* STATE_H_ */
