#include <stdint.h>
#include <stdio.h>
#include "mc.h"
#define threshold 20

void (*pMain_controller_State)();

//global variables to the block
static int pressure_val=0;

void send_pressure_val(int pval)
{	
	pressure_val = pval;
}

void MC_pressure_reading()
{
    if(pressure_val >= threshold)
    {
        high_pressure_detected();
    }
    pMain_controller_State=MC_pressure_reading;
}