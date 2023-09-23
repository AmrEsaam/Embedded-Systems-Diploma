/* Startup.c for ARM Cortex M3
By: Eng. Amr Zidan
*/

#include <stdint.h>

extern uint32_t main (void);
extern uint32_t _E_text ;
extern uint32_t _S_data ;
extern uint32_t _E_data ;
extern uint32_t _S_bss ;
extern uint32_t _E_bss ;


void Reset_Handler ();
void Default_Handler ();
void NMI_Handler () __attribute__ ((weak,alias("Default_Handler")));
void H_Fault_Handler () __attribute__ ((weak,alias("Default_Handler")));


// booking 1024 B in .bss section using global uninitialized arry of 256 integer elements
uint32_t static Stack_top[256];

 void (* g_p_fun[])() __attribute__((section(".vectors"))) =
    {
        (void (*)()) ((uint32_t)Stack_top + sizeof(Stack_top)),
        &Reset_Handler,
        &NMI_Handler,
        &H_Fault_Handler
    };

void Default_Handler ()
{
    Reset_Handler();
}


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


