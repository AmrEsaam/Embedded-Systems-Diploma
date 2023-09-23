/* Startup.c for ARM Cortex M3
By: Eng. Amr Zidan
*/

#include <stdint.h>

void Reset_Handler ();
void Default_Handler ();
void NMI_Handler () __attribute__ ((weak,alias("Default_Handler")));;
void H_Fault_Handler () __attribute__ ((weak,alias("Default_Handler")));;
void MM_Handler () __attribute__ ((weak,alias("Default_Handler")));;
void Bus_Fault_Handler () __attribute__ ((weak,alias("Default_Handler")));;
void Usage_Fault_Handler () __attribute__ ((weak,alias("Default_Handler")));;


uint32_t vetors[] __attribute__((section(".vectors"))) ={
    (uint32_t) 0x20001000,
    (uint32_t) &Reset_Handler,
    (uint32_t) &NMI_Handler,
    (uint32_t) &H_Fault_Handler,
    (uint32_t) &MM_Handler,
    (uint32_t) &Bus_Fault_Handler,
    (uint32_t) &Usage_Fault_Handler
};

void Default_Handler ()
{
    Reset_Handler();
}

extern uint32_t main (void);
extern uint32_t _E_text ;
extern uint32_t _S_data ;
extern uint32_t _E_data ;
extern uint32_t _S_bss ;
extern uint32_t _E_bss ;

void Reset_Handler ()
{
    uint32_t data_size = (uint8_t*)&_E_data - (uint8_t*)&_S_data ;
    uint8_t* p_src = (uint8_t*)&_E_text ;
    uint8_t* p_dest = (uint8_t*)&_S_data ;
    uint32_t i=0;

    for (i = 0; i < data_size; i++)
    {
       *((uint8_t*)p_dest++) = *((uint8_t*)p_src++);
    }

    // .bss initalization

    uint32_t bss_size = (uint8_t*)&_E_bss - (uint8_t*)&_S_bss ;
    p_dest = (uint8_t*)&_S_bss ;
    for (i = 0; i < bss_size; i++)
    {
       *((uint8_t*)p_dest++) = (uint8_t)0;
    }
    
    // jump to main
    main();
}


