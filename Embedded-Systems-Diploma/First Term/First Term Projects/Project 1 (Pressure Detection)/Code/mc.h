#ifndef MAIN_CONTROLLER_H_
#define MAIN_CONTROLLER_H_
#include "state.h"
#include "driver.h"

//define states
enum{
    MC_pressure_reading_state
}
MC_state;

//states
STATE_DEFINE(MC_pressure_reading);

#endif