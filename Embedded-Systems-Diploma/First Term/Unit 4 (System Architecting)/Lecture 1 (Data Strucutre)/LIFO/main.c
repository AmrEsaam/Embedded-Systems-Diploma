/*
 * main.c
 *
 *  Created on: Sep 9, 2023
 *      Author: Amr
 */

#include <stdio.h>
#include <stdlib.h>
#include "lifo.h"

#define Buffer_Length 5
uint8_t Buffer1[Buffer_Length]; //buffer for static allocation 5*1=1

int main (void)
{
	uint8_t i=0, temp=0;
	LIFO_Buffer_t UART_LIFO_Buf, I2C_LIFO_Buf;
	//static allocation
	LIFO_Init(&UART_LIFO_Buf,Buffer1,Buffer_Length);
	//dynamic allocation
	uint8_t* Buffer2 = (uint8_t*) malloc(5*sizeof(char)); //buffer for dynamic allocation 5*1=1
	LIFO_Init(&I2C_LIFO_Buf,Buffer2,Buffer_Length);

	//test code for UART
	for(i=0;i<5;i++)
	{
		if(LIFO_Push_Item(&UART_LIFO_Buf,i) == LIFO_no_error)
		{
			printf("UART_LIFO add number %d \n",i);
			fflush(stdin);
		}
	}

	for(i=0;i<5;i++)
	{
		{
			if(LIFO_Pop_Item(&UART_LIFO_Buf,&temp) == LIFO_no_error)
			{
				printf("UART_LIFO get number %d \n",temp);
				fflush(stdin);
			}
		}
	}





	return 0;
}


