#include "alarm_monitor.h"

//global variables to the block ---> none

//state pointer (ptr to function)
void (*pAlarm_monitor_State)();

//high pressure detected function body
int high_pressure_detected()
{
   pAlarm_monitor_State=alarm_monitor_on;
}


//waiting state
STATE_DEFINE(alarm_monitor_off)
{
    //state id
    alarm_monitor_state_id=alarm_monitor_off_state;

    //state action
    set_alarm_off();


}


STATE_DEFINE(alarm_monitor_on)
{
    //state id
    alarm_monitor_state_id=alarm_monitor_on_state;

    //state action
    set_alarm_on();
    Delay(ALARM_DURATION); //alarm duration = 60 seconds

    //go to alarm off state
    pAlarm_monitor_State=alarm_monitor_off;
}