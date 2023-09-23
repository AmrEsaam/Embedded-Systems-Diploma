#include "uart.h"

uint8_t string_buffer[100]="learn-in-depth:Amr_Zidan";
uint8_t const string_buffer2[100]="learn-in-depth:Amr_Zidan";
void main (void)
{
    UART_SEND_STRING(string_buffer);
}