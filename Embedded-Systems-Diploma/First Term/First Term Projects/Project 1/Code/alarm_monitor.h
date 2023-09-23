#ifndef ALARM_MONITOR_H_
#define ALARM_MONITOR_H_

#include "state.h"
#include "driver.h"
#define ALARM_DURATION 60

//define states
enum {
    alarm_monitor_on_state,
    alarm_monitor_off_state
}alarm_monitor_state_id;

//states
STATE_DEFINE(alarm_monitor_on);
STATE_DEFINE(alarm_monitor_off);


#endif