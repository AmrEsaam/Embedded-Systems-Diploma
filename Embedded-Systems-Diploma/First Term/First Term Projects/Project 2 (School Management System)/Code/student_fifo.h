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
#include <string.h>

#define COURSE_NUM 5

typedef struct 
{
    char f_name[50];
    char l_name[50];
    int roll_num;
    float GPA;
    int course_id[COURSE_NUM];
}Student_t;

//User Configuration
#define element_type Student_t 		 //define element type (uint8_t, uint32_t,.......)
#define buffer_length 50 			 //define the length of the created buffer


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
	FIFO_no_error,
}FIFO_Status_t;

typedef enum{
	ID_EXISTS,
	ID_AVAILABLE
}ID_Status_t;

//APIs
FIFO_Status_t FIFO_Init(FIFO_Buffer_t* FIFO_Buf, element_type* ALLOC_Buf, uint8_t length);
FIFO_Status_t FIFO_add_student(FIFO_Buffer_t* FIFO_Buf);
FIFO_Status_t FIFO_add_student_file(FIFO_Buffer_t* FIFO_Buf);
FIFO_Status_t FIFO_delete_student(FIFO_Buffer_t* FIFO_Buf);
FIFO_Status_t FIFO_find_roll_num(FIFO_Buffer_t* FIFO_Buf);
FIFO_Status_t FIFO_find_first_name(FIFO_Buffer_t* FIFO_Buf);
FIFO_Status_t FIFO_find_course(FIFO_Buffer_t* FIFO_Buf);
FIFO_Status_t FIFO_count(FIFO_Buffer_t* FIFO_Buf);
FIFO_Status_t FIFO_update_student(FIFO_Buffer_t* FIFO_Buf);
FIFO_Status_t FIFO_show_info(FIFO_Buffer_t* FIFO_Buf);
void FIFO_Print(FIFO_Buffer_t* FIFO_Buf);
FIFO_Status_t FIFO_IS_FULL(FIFO_Buffer_t* FIFO_Buf);
ID_Status_t FIFO_check_id(FIFO_Buffer_t* FIFO_Buf, int id);





#endif /* FIFO_H_ */
