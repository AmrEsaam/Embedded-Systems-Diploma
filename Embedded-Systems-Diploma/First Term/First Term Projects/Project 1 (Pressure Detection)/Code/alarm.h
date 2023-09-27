#ifndef ALARM_H_
#define ALARM_H_

#include "state.h"

//define states
enum {
    alarm_waiting_state,
    alarm_on_state,
    alarm_off_state
}alarm_state_id;

//states
STATE_DEFINE(alarm_waiting);
STATE_DEFINE(alarm_on);
STATE_DEFINE(alarm_off);

void alarm_init();

#endif