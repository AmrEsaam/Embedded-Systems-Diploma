#ifndef PRESSURE_SENSOR_H_
#define PRESSURE_SENSOR_H_

#include "state.h"
#define sensor_pull_time 100

//define states
enum {
    pressure_sensor_reading_state,
    pressure_sensor_waiting_state
}pressure_sensor_state_id;

//states
STATE_DEFINE(pressure_sensor_reading);
STATE_DEFINE(pressure_sensor_waiting);

void pressure_sensor_init();

#endif