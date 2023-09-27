#include <stdint.h>
#include <stdio.h>
#include "pressure_sensor.h"
#include "mc.h"
#include "alarm_monitor.h"
#include "alarm.h"


extern void (*pPressure_sensor_State)();
extern void (*pMain_controller_State)();
extern void (*pAlarm_monitor_State)();
extern void (*pAlarm_State)();



void setup()
{
	//init all drivers
    //init IRQ
    //init US & DC_MOTOR
    //init block
	pressure_sensor_init();
	alarm_init();
	GPIO_INITIALIZATION();
    //Set state ptr for each block
	pPressure_sensor_State=STATE(pressure_sensor_reading);
	pMain_controller_State=STATE(MC_pressure_reading);
	pAlarm_monitor_State=STATE(alarm_monitor_off);
	pAlarm_State=STATE(alarm_waiting);
}


int main ()
{
	setup();
	while (1)
	{
		pPressure_sensor_State();
		pMain_controller_State();
		pAlarm_monitor_State();
		pAlarm_State();
	}
}
