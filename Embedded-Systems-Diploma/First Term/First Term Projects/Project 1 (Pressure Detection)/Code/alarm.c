#include "alarm.h"
#include "driver.h"

//global variables to the block ---> none

//state pointer (ptr to function)
void (*pAlarm_State)();


//init alarm driver
void alarm_init()
{
    //init
}

//alarm on function body
void set_alarm_on()
{
    Set_Alarm_actuator(1);
}

//alarm off function body
void set_alarm_off()
{
    Set_Alarm_actuator(0);
}


//waiting state
STATE_DEFINE(alarm_waiting)
{
    //state id
    alarm_state_id=alarm_waiting_state;

    //state action ---> none
}

//alarm on state
STATE_DEFINE(alarm_on)
{
    //state id
    alarm_state_id=alarm_on_state;

    //state action
    pAlarm_State=alarm_waiting;
}

//alarm off state
STATE_DEFINE(alarm_off)
{
    //state id
    alarm_state_id=alarm_off_state;

    //state action
    pAlarm_State=alarm_waiting;
}