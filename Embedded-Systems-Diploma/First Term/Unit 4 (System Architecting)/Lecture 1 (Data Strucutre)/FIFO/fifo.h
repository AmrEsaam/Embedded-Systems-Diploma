/*
 * fifo.h
 *
 *  Created on: Sep 9, 2023
 *      Author: Amr
 */

#ifndef FIFO_H_
#define FIFO_H_
#include <stdio.h>
#include <stdint.h>


//User Configuration
#define element_type uint8_t 		 //define element type (uint8_t, uint32_t,.......)
#define buffer_length 5 			 //define the length of the created buffer
element_type Buffer[buffer_length];


//Type Definitions
typedef struct{
	element_type* head;
	element_type* tail;
	element_type* base ;
	uint32_t count;
	uint32_t length;
}FIFO_Buffer_t;

typedef enum {
	FIFO_null,
	FIFO_full,
	FIFO_empty,
	FIFO_no_error
}FIFO_Status_t;


//APIs
FIFO_Status_t FIFO_Init(FIFO_Buffer_t* FIFO_Buf, element_type* ALLOC_Buf, uint8_t length);
FIFO_Status_t FIFO_Enqueue(FIFO_Buffer_t* FIFO_Buf, element_type item);
FIFO_Status_t FIFO_Dequeue(FIFO_Buffer_t* FIFO_Buf, element_type* item);
FIFO_Status_t FIFO_IS_FULL(FIFO_Buffer_t* FIFO_Buf);
void FIFO_Print(FIFO_Buffer_t* FIFO_Buf);




#endif /* FIFO_H_ */
