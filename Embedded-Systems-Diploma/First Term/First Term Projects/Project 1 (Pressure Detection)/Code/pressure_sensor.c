#include "pressure_sensor.h"
#include "driver.h"



//global variables to the block
static int pressure_val=0;

//state pointer (ptr to function)
void (*pPressure_sensor_State)();



//init pressure_sensor driver
void pressure_sensor_init()
{
    //init
}


//reading state
STATE_DEFINE(pressure_sensor_reading)
{
    //state id
    pressure_sensor_state_id=pressure_sensor_reading_state;

     //state action
    pressure_val=getPressureVal();
    send_pressure_val(pressure_val);

    //go to waiting state
    pPressure_sensor_State=pressure_sensor_waiting;
}



//waiting state
STATE_DEFINE(pressure_sensor_waiting)
{
    //state id
    pressure_sensor_state_id=pressure_sensor_waiting_state;

    //timer expires
    Delay(sensor_pull_time);
    //timer reset
    
    //go to reading state
    pPressure_sensor_State=pressure_sensor_reading;
}