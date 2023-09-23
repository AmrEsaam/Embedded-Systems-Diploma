#include "uart.h"
#define UART0DR *((volatile uint32_t* const)((uint32_t*)0x101f1000))

void UART_SEND_STRING (unsigned char *string)
{
    while(*string!='\0')
    {
        UART0DR= (uint32_t)(*string);
        string++;
    }
}