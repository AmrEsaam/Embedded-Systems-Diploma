/*
 * lifo.c
 *
 *  Created on: Sep 9, 2023
 *      Author: Amr
 */
#include "lifo.h"
#include <stdio.h>
#include <stdlib.h>

LIFO_Status_t LIFO_Init(LIFO_Buffer_t* LIFO_Buffer, uint8_t* ALLOC_Buffer, uint32_t length)
{
    if(ALLOC_Buffer == NULL)
        return LIFO_null;
    
    LIFO_Buffer->head=ALLOC_Buffer;
    LIFO_Buffer->base=ALLOC_Buffer;
    LIFO_Buffer->length=length;
    LIFO_Buffer->count=0;
    return LIFO_no_error;
}


LIFO_Status_t LIFO_Push_Item(LIFO_Buffer_t* LIFO_Buf,uint8_t item)
{
    //check if lifo is valid
    if(!LIFO_Buf->head || !LIFO_Buf->base)
        return LIFO_null;

    //check if lifo is full
    if(LIFO_Buf->count == LIFO_Buf->length)
        return LIFO_full;

    //push value
    (*LIFO_Buf->head)=item;
    LIFO_Buf->head++;
    LIFO_Buf->count++;
    return LIFO_no_error;

}


LIFO_Status_t LIFO_Pop_Item(LIFO_Buffer_t* LIFO_Buf,uint8_t* item)
{
    //check if lifo is valid
    if(!LIFO_Buf->head || !LIFO_Buf->base)
        return LIFO_null;

    //check if lifo is empty
    if(LIFO_Buf->count == 0)
        return LIFO_empty;

    //pop value
    LIFO_Buf->head--;
    *item=*(LIFO_Buf->head);
    LIFO_Buf->count--;
    return LIFO_no_error;
}

