/*
 * fifo.c
 *
 *  Created on: Sep 9, 2023
 *      Author: Amr
 */
#include "fifo.h"


FIFO_Status_t FIFO_Init(FIFO_Buffer_t* FIFO_Buf, element_type* ALLOC_Buf, uint8_t length)
{
    if(!FIFO_Buf->base || !FIFO_Buf->head || !FIFO_Buf->tail)
        return FIFO_null;
    
    FIFO_Buf->base=ALLOC_Buf;
    FIFO_Buf->head=ALLOC_Buf;
    FIFO_Buf->tail=ALLOC_Buf;
    FIFO_Buf->count=0;
    FIFO_Buf->length=length;
    return FIFO_no_error;
}


FIFO_Status_t FIFO_Enqueue(FIFO_Buffer_t* FIFO_Buf, element_type item)
{
    if(!FIFO_Buf->base || !FIFO_Buf->head || !FIFO_Buf->tail)
        return FIFO_null;
    
    if(FIFO_IS_FULL(FIFO_Buf) == FIFO_full)
        return FIFO_full;

    *(FIFO_Buf->head)=item;
    FIFO_Buf->count++;

    //Circular Queue
    if(FIFO_Buf->head == (FIFO_Buf->base + (FIFO_Buf->length*sizeof(element_type))))
        FIFO_Buf->head=FIFO_Buf->base;
    else
        FIFO_Buf->head++;

    return FIFO_no_error;
}


FIFO_Status_t FIFO_Dequeue(FIFO_Buffer_t* FIFO_Buf, element_type* item)
{
    if(!FIFO_Buf->base || !FIFO_Buf->head || !FIFO_Buf->tail)
        return FIFO_null;

    if(FIFO_Buf->count == 0)
        return FIFO_empty;

    *item = *(FIFO_Buf->tail);
    FIFO_Buf->count--;

    //Circular Queue
    if(FIFO_Buf->tail == (FIFO_Buf->base + (FIFO_Buf->length*sizeof(element_type))))
        FIFO_Buf->tail=FIFO_Buf->base;
    else
        FIFO_Buf->tail++;

    return FIFO_no_error;

    
}


FIFO_Status_t FIFO_IS_FULL(FIFO_Buffer_t* FIFO_Buf)
{
    if(!FIFO_Buf->base || !FIFO_Buf->head || !FIFO_Buf->tail)
        return FIFO_null;

    if(FIFO_Buf->count == FIFO_Buf->length)
        return FIFO_full;

    return FIFO_no_error;
}


void FIFO_Print(FIFO_Buffer_t* FIFO_Buf)
{
    element_type *temp=0;
    uint8_t i=0;

    if(!FIFO_Buf->base || !FIFO_Buf->head || !FIFO_Buf->tail)
    {
        printf("Invalid Buffer");
    }
        

    if(FIFO_Buf->count == 0)
    {
        printf("\n-----FIFO is empty-----\n");
    }


    temp=FIFO_Buf->tail;
    printf("-----FIFO Print-----\n");

    for (i = 0; i < FIFO_Buf->count; i++)
    {
        printf("\t %X \n",*temp);
        temp++;
    }
    
    printf("\n-----Print is done-----\n");
    
}

