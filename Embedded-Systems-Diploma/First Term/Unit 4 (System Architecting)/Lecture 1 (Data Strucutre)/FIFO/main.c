/*
 * main.c
 *
 *  Created on: Sep 9, 2023
 *      Author: Amr
 */

#include "fifo.h"


int main(void)
{
    element_type i=0, temp=0;
    FIFO_Buffer_t UART_Buf;
    //init
    if (FIFO_Init(&UART_Buf,Buffer,5) == FIFO_no_error)
        printf("-----FIFO Initialization is done-----\n");

    //Enqueue test
    for (i = 0; i < 7; i++)
    {
        printf("\nFIFO Enqueue (%X)",i);
        if(FIFO_Enqueue(&UART_Buf,i) == FIFO_no_error)
            printf("-----FIFO Enqueue is done-----");
        else
            printf("\n-----FIFO Enqueue failed-----\n");
    }
    FIFO_Print(&UART_Buf);

    //Dequeue test
    for (i = 0; i < 2; i++)
    {
        if(FIFO_Dequeue(&UART_Buf,&temp) == FIFO_no_error)
            printf("-----FIFO Dequeue is done (%X)-----\n",temp);
        else
            printf("-----FIFO Dequeue failed-----\n");
    }
    FIFO_Print(&UART_Buf);
    





    return 0;
}
