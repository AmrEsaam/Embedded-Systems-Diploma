/*
 * lifo.h
 *
 *  Created on: Sep 9, 2023
 *      Author: Amr
 */

#ifndef LIFO_H_
#define LIFO_H_
#include<stdint.h>

//Type Definitions

typedef struct {
    uint32_t length;
    uint32_t count;
    uint8_t* base;
    uint8_t* head;
}LIFO_Buffer_t;

typedef enum{
    LIFO_no_error,
    LIFO_full,
    LIFO_empty,
    LIFO_null
}LIFO_Status_t;




//APIs

LIFO_Status_t LIFO_Init(LIFO_Buffer_t* LIFO_Buf, uint8_t* ALLOC_Buffer, uint32_t length);
LIFO_Status_t LIFO_Push_Item(LIFO_Buffer_t* LIFO_Buf,uint8_t item);
LIFO_Status_t LIFO_Pop_Item(LIFO_Buffer_t* LIFO_Buf,uint8_t* item);





#endif /* LIFO_H_ */
