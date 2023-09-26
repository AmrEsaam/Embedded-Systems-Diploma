/*
 * student_fifo.c
 *
 *  Created on: Sep 9, 2023
 *      Author: Amr
 */
#include "student_fifo.h"




/**
 ****************************************************************************************
 * @function_name	: FIFO_init
 * @brief			: it used to initialize the buffer.
 * @arguments		: @parameter *FIFO_Buf it is a pointer to the structure of the student, Array pointer and length of the array.
 *****************************************************************************************
 **/
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












/**
 ****************************************************************************************
 * @function_name	: FIFO_IS_FULL
 * @brief			: it used to check if the fifo buffer is full.
 * @arguments		: @parameter *FIFO_Buf it is a pointer to the structure of the student.
 *****************************************************************************************
 **/
FIFO_Status_t FIFO_IS_FULL(FIFO_Buffer_t* FIFO_Buf)
{
    if(!FIFO_Buf->base || !FIFO_Buf->head || !FIFO_Buf->tail)
        return FIFO_null;

    if(FIFO_Buf->count == FIFO_Buf->length)
        return FIFO_full;

    return FIFO_no_error;
}











/**
 ****************************************************************************************
 * @function_name	: FIFO_check_id
 * @brief			: it used to check if the student id exists.
 * @arguments		: @parameter *FIFO_Buf it is a pointer to the structure of the student and the student ID.
 *****************************************************************************************
 **/
ID_Status_t FIFO_check_id(FIFO_Buffer_t* FIFO_Buf, int id)
{
    int i=0;
    element_type* p_Student=FIFO_Buf->tail;

    for(i=0;i<FIFO_Buf->count;i++)
    {
        if(p_Student->roll_num == id)
        {
            return ID_EXISTS;
        }
        
        return ID_AVAILABLE;
    }
}












/**
 ****************************************************************************************
 * @function_name	: FIFO_add_student_file
 * @brief			: it used to add students from a file.
 * @arguments		: @parameter *FIFO_Buf it is a pointer to the structure of the student.
 *****************************************************************************************
 **/
FIFO_Status_t FIFO_add_student_file(FIFO_Buffer_t* FIFO_Buf)
{
    int i=0, flag=0;
    element_type* p_Student=FIFO_Buf->tail;
    Student_t New_Student;
    FILE *P_File = fopen("file.txt", "r+");

    if(!FIFO_Buf->base || !FIFO_Buf->head || !FIFO_Buf->tail)
    {
        printf("\n------------------------------------------------------");
        printf("(ERROR) Fifo isn't initialized");
        printf("\n------------------------------------------------------");
        return FIFO_null;
    }
        
    
    if(FIFO_IS_FULL(FIFO_Buf) == FIFO_full)
    {   
        printf("\n------------------------------------------------------");
        printf("(ERROR) Fifo is full");
        printf("\n------------------------------------------------------");
        return FIFO_full;
    }
   

	if(P_File)
	{
		//loop till the end of the file.
		while(!feof(P_File))
		{
			//scan values from the text file
			fscanf(P_File,"%s %s %d %f %d %d %d %d %d\n",New_Student.f_name, New_Student.l_name, &New_Student.roll_num, &New_Student.GPA,
					&New_Student.course_id[0], &New_Student.course_id[1], &New_Student.course_id[2],
					&New_Student.course_id[3], &New_Student.course_id[4]);

			//check if the id is exist in database or not
            for(i=0;i<FIFO_Buf->count;i++)
            {  
                if(New_Student.roll_num == p_Student->roll_num)
                flag=1;
            }
            if(flag==0)
            {
				strcpy(FIFO_Buf->head->f_name,New_Student.f_name);
				strcpy(FIFO_Buf->head->l_name,New_Student.l_name);
				FIFO_Buf->head->roll_num= New_Student.roll_num;
				FIFO_Buf->head->GPA = New_Student.GPA;
				for(int i = 0; i < COURSE_NUM; i++)
				{
					FIFO_Buf->head->course_id[i] = New_Student.course_id[i];
				}
				FIFO_Buf->count++;
				//check if the head at the last element in the array.
				if(FIFO_Buf->head == (FIFO_Buf->base + (FIFO_Buf->length * sizeof(element_type))))
					FIFO_Buf->head = FIFO_Buf->base;
				else
						FIFO_Buf->head++;

				printf("\n------------------------------------------------------------");
				printf("\n(INFO) Student with roll number (%d) is added successfully",New_Student.roll_num);
				printf("\n------------------------------------------------------------");
            }
            else
            {
                printf("\n------------------------------------------------------");
                printf("(ERROR) Roll number already exists");
                printf("\n------------------------------------------------------");
            }
		}
	}
	else
	{
		printf("\n------------------------------------------------------");
		printf("(ERROR) file.txt File Not Found.\n");
		printf("\n------------------------------------------------------");
	}

}









/**
 ****************************************************************************************
 * @function_name	: FIFO_add_student
 * @brief			: it used to add a student manually.
 * @arguments		: @parameter *FIFO_Buf it is a pointer to the structure of the student.
 *****************************************************************************************
 **/
FIFO_Status_t FIFO_add_student(FIFO_Buffer_t* FIFO_Buf)
{
    int i=0, id=0, flag=0;
    element_type* p_Student=FIFO_Buf->tail;

    if(!FIFO_Buf->base || !FIFO_Buf->head || !FIFO_Buf->tail)
    {
        printf("\n------------------------------------------------------");
        printf("(ERROR) Fifo isn't initialized");
        printf("\n------------------------------------------------------");
        return FIFO_null;
    }
        
    
    if(FIFO_IS_FULL(FIFO_Buf) == FIFO_full)
    {   
        printf("\n------------------------------------------------------");
        printf("(ERROR) Fifo is full");
        printf("\n------------------------------------------------------");
        return FIFO_full;
    }

    printf("\nEnter the student roll number: ");
    scanf("%d",&id);

    for(i=0;i<FIFO_Buf->count;i++)
    {
        if(id == p_Student->roll_num)
            flag=1;
    }
    
    if(flag==0)
    {
     
        FIFO_Buf->head->roll_num=id;

        printf("\nEnter the student first name: ");
        scanf("%s",FIFO_Buf->head->f_name);

        printf("\nEnter the student last name: ");
        scanf("%s",FIFO_Buf->head->l_name);

        printf("\nEner the student GPA: ");
        scanf("%f",&FIFO_Buf->head->GPA);

        printf("\nEnter the student course IDs ");
        for(i=0;i<COURSE_NUM;i++)
        {
            printf("\nEnter course number %d ID: ",i+1);
            scanf("%d",&FIFO_Buf->head->course_id[i]);
        }

        //Circular Queue
        if(FIFO_Buf->head == (FIFO_Buf->base + (FIFO_Buf->length*sizeof(element_type))))
            FIFO_Buf->head=FIFO_Buf->base;
        else
            FIFO_Buf->head++;
        
        FIFO_Buf->count++;

        printf("\n------------------------------------------------------------");
        printf("\n(INFO) Student with roll number (%d) is added successfully",FIFO_Buf->head->roll_num);
        printf("\n------------------------------------------------------------");
    }
    else
    {
        printf("\n------------------------------------------------------");
        printf("\n(ERROR) Roll number (%d) already exists",id);
        printf("\n------------------------------------------------------");
        return ID_EXISTS;
    }
   
    
    return FIFO_no_error;
}










/**
 ****************************************************************************************
 * @function_name	: FIFO_find_roll_num
 * @brief			: it used to search for a student using roll number.
 * @arguments		: @parameter *FIFO_Buf it is a pointer to the structure of the student.
 *****************************************************************************************
 **/
FIFO_Status_t FIFO_find_roll_num(FIFO_Buffer_t* FIFO_Buf)
{
    uint32_t i=0, id=0, j=0;
    element_type* p_Student=FIFO_Buf->tail;

    if(!FIFO_Buf->base || !FIFO_Buf->head || !FIFO_Buf->tail)
    {
        printf("\n------------------------------------------------------");
        printf("\n(ERROR) Fifo isn't initialized");
        printf("\n------------------------------------------------------");
        return FIFO_null;
    }
    
        

    if(FIFO_Buf->count == 0)
    {
        printf("\n------------------------------------------------------");
        printf("\n(ERROR) Fifo is empty");
        printf("\n------------------------------------------------------");
        return FIFO_empty;
    }


    printf("\nEnter the student roll number: ");
    scanf("%d",&id);

    for(i=0;i<FIFO_Buf->count;i++)
    {
        if(p_Student->roll_num == id)
        {
            printf("\nStudent data: ");
            printf("\nStudent first name: %s",p_Student->f_name);
            printf("\nStudent last name: %s",p_Student->l_name);
            printf("\nStudent roll number: %d",p_Student->roll_num);
            printf("\nStudent GPA: %f",p_Student->GPA);
            for(j=0;j<COURSE_NUM;j++)
            {
                printf("\nStudent registered course number %d: %d",j,p_Student->course_id[j]);
            }
        }
        p_Student++;
    }
    p_Student=FIFO_Buf->tail;
}












/**
 ****************************************************************************************
 * @function_name	: FIFO_find_first_name
 * @brief			: it used to search for a student using first name.
 * @arguments		: @parameter *FIFO_Buf it is a pointer to the structure of the student.
 *****************************************************************************************
 **/
FIFO_Status_t FIFO_find_first_name(FIFO_Buffer_t* FIFO_Buf)
{
    uint32_t i=0, j=0;
    element_type* p_Student=FIFO_Buf->tail;
    char first_name[50];

    if(!FIFO_Buf->base || !FIFO_Buf->head || !FIFO_Buf->tail)
    {
        printf("\n------------------------------------------------------");
        printf("\n(ERROR) Fifo isn't initialized");
        printf("\n------------------------------------------------------");
        return FIFO_null;
    }
    
        

    if(FIFO_Buf->count == 0)
    {
        printf("\n------------------------------------------------------");
        printf("\n(ERROR) Fifo is empty");
        printf("\n------------------------------------------------------");
        return FIFO_empty;
    }

    printf("\nEnter the student first name: ");
    scanf("%s",first_name);

    for(i=0;i<FIFO_Buf->count;i++)
    {
        if(!strcmp(p_Student->f_name, first_name))
        {
            printf("\nStudent data: ");
            printf("\nStudent first name: %s",p_Student->f_name);
            printf("\nStudent last name: %s",p_Student->l_name);
            printf("\nStudent roll number: %d",p_Student->roll_num);
            printf("\nStudent GPA: %f",p_Student->GPA);
            for(j=0;j<COURSE_NUM;j++)
            {
                printf("\nStudent registered course number %d: %d",j,p_Student->course_id[j]);
            }
        }
        p_Student++;
    }
    p_Student=FIFO_Buf->tail;
}











/**
 ****************************************************************************************
 * @function_name	: FIFO_find_course
 * @brief			: it used to search for a student using course id.
 * @arguments		: @parameter *FIFO_Buf it is a pointer to the structure of the student.
 *****************************************************************************************
 **/
FIFO_Status_t FIFO_find_course(FIFO_Buffer_t* FIFO_Buf)
{
    uint32_t i=0, course=0, j=0, count=0;
    element_type* p_Student=FIFO_Buf->tail;

   if(!FIFO_Buf->base || !FIFO_Buf->head || !FIFO_Buf->tail)
    {
        printf("\n------------------------------------------------------");
        printf("\n(ERROR) Fifo isn't initialized");
        printf("\n------------------------------------------------------");
        return FIFO_null;
    }
    
        

    if(FIFO_Buf->count == 0)
    {
        printf("\n------------------------------------------------------");
        printf("\n(ERROR) Fifo is empty");
        printf("\n------------------------------------------------------");
        return FIFO_empty;
    }

    printf("\nEnter the course id: ");
    scanf("%d",&course);

    for(i=0;i<FIFO_Buf->count;i++)
    {
        for(count=0;count<COURSE_NUM;count++)
        {
            if(p_Student->course_id[count] == course)
            {
                printf("\nStudent data: ");
                printf("\nStudent first name: %s",p_Student->f_name);
                printf("\nStudent last name: %s",p_Student->l_name);
                printf("\nStudent roll number: %d",p_Student->roll_num);
                printf("\nStudent GPA: %f",p_Student->GPA);
                for(j=0;j<COURSE_NUM;j++)
                {
                    printf("\nStudent registered course number %d: %d",j,p_Student->course_id[j]);
                }
            }
        }
        p_Student++;
    }
    p_Student=FIFO_Buf->tail;
}











/**
 ****************************************************************************************
 * @function_name	: FIFO_count
 * @brief			: it used to count the number of students.
 * @arguments		: @parameter *FIFO_Buf it is a pointer to the structure of the student.
 *****************************************************************************************
 **/
FIFO_Status_t FIFO_count(FIFO_Buffer_t* FIFO_Buf)
{
   if(!FIFO_Buf->base || !FIFO_Buf->head || !FIFO_Buf->tail)
    {
        printf("\n------------------------------------------------------");
        printf("\n(ERROR) Fifo isn't initialized");
        printf("\n------------------------------------------------------");
        return FIFO_null;
    }
    
        

    if(FIFO_Buf->count == 0)
    {
        printf("\n------------------------------------------------------");
        printf("\n(ERROR) Fifo is empty");
        printf("\n------------------------------------------------------");
        return FIFO_empty;
    }

    printf("The total number of students registered is: %d",FIFO_Buf->count);
}











/**
 ****************************************************************************************
 * @function_name	: FIFO_delete_student
 * @brief			: it used to delete a student.
 * @arguments		: @parameter *FIFO_Buf it is a pointer to the structure of the student.
 *****************************************************************************************
 **/
FIFO_Status_t FIFO_delete_student(FIFO_Buffer_t* FIFO_Buf)
{
    element_type* p_Student=FIFO_Buf->tail;
    int i=0, j=0, counter=0, id=0;
if(!FIFO_Buf->base || !FIFO_Buf->head || !FIFO_Buf->tail)
    {
        printf("\n------------------------------------------------------");
        printf("\n(ERROR) Fifo isn't initialized");
        printf("\n------------------------------------------------------");
        return FIFO_null;
    }
    
        

    if(FIFO_Buf->count == 0)
    {
        printf("\n------------------------------------------------------");
        printf("\n(ERROR) Fifo is empty");
        printf("\n------------------------------------------------------");
        return FIFO_empty;
    }

    printf("\nEnter the roll number you want to delete: ");
    scanf("%d",&id);

    for(i=0;i<FIFO_Buf->count;i++)
    {
        if(id == p_Student->roll_num)
        {
            for(j=i;j<FIFO_Buf->count;j++)
            {
                if(p_Student == (FIFO_Buf->base + ((FIFO_Buf->length)*sizeof(element_type))))
                {
                    *(p_Student)=*(FIFO_Buf->base);
                    p_Student=FIFO_Buf->base;
                }
                else
                {
                    *(p_Student)=*(p_Student+1);
                }
            }
            FIFO_Buf->count--;
            
            printf("\n------------------------------------------------------------");
            printf("\nThe student of roll number: (%d) is removed successfully",id);
            printf("\n------------------------------------------------------------");
        }
        else
        {
            if(p_Student == (FIFO_Buf->base + ((FIFO_Buf->length)*sizeof(element_type))))
            {
                p_Student=FIFO_Buf->base;
            }
            else
            {
                p_Student++;
            }
        }
    }

    return FIFO_no_error;

    
}









/**
 ****************************************************************************************
 * @function_name	: FIFO_update_student
 * @brief			: it used to update the data of a student.
 * @arguments		: @parameter *FIFO_Buf it is a pointer to the structure of the student.
 *****************************************************************************************
 **/
FIFO_Status_t FIFO_update_student(FIFO_Buffer_t* FIFO_Buf)
{
    int i=0, j=0, id=0, choice=0, new_GPA=0, old_course=0, new_course=0;
    char first_name[50], last_name[50];
    element_type* p_Student=FIFO_Buf->tail;

   if(!FIFO_Buf->base || !FIFO_Buf->head || !FIFO_Buf->tail)
    {
        printf("\n------------------------------------------------------");
        printf("\n(ERROR) Fifo isn't initialized");
        printf("\n------------------------------------------------------");
        return FIFO_null;
    }
    
        

    if(FIFO_Buf->count == 0)
    {
        printf("\n------------------------------------------------------");
        printf("\n(ERROR) Fifo is empty");
        printf("\n------------------------------------------------------");
        return FIFO_empty;
    }

    printf("\nEnter the student roll number: ");
    scanf("%d",&id);

    for(i=0;i<FIFO_Buf->count;i++)
    {
        if(p_Student->roll_num == id)
        {
           printf("\nWhat do you want to update?");
           printf("\n(1)roll number \n(2)first name \n(3)last name \n(4)GPA \n(5)course id\nChoice: ");

           scanf("%d",&choice);

           switch (choice)
           {
           case 1:
            printf("\nEnter the new roll number: ");
            scanf("%d",&id);
            p_Student->roll_num=id;
            break;

            case 2:
             printf("\nEnter the new first name: ");
             scanf("%s",first_name);
             strcpy(p_Student->f_name,first_name);
             break;

            case 3:
             printf("\nEnter the new last name: ");
             scanf("%s",last_name);
             strcpy(p_Student->l_name,last_name);
             break;

            case 4:
             printf("\nEnter the new GPA: ");
             scanf("%f",&new_GPA);
             p_Student->GPA=new_GPA;
             break;

            case 5:
             printf("\nEnter the old course id ");
             scanf("%d",&old_course);
             for(j=0;j<COURSE_NUM;j++)
             {
                if(p_Student->course_id[j] == old_course)
                {
                    printf("\nEnter the new course id ");
                    scanf("%d",&new_course);
                    p_Student->course_id[j]=new_course;
                }
             }
             break;
             
           default:
            break;
           }
        }
        p_Student++;
    }
    p_Student=FIFO_Buf->tail;
}













/**
 ****************************************************************************************
 * @function_name	: FIFO_show_info
 * @brief			: it used to show the students' information.
 * @arguments		: @parameter *FIFO_Buf it is a pointer to the structure of the student.
 *****************************************************************************************
 **/
FIFO_Status_t FIFO_show_info(FIFO_Buffer_t* FIFO_Buf)
{
    int i=0, j=0;
    element_type* p_Student = FIFO_Buf->tail;

    if(!FIFO_Buf->base || !FIFO_Buf->head || !FIFO_Buf->tail)
    {
        printf("\n------------------------------------------------------");
        printf("\n(ERROR) Fifo isn't initialized");
        printf("\n------------------------------------------------------");
        return FIFO_null;
    }
    
        

    if(FIFO_Buf->count == 0)
    {
        printf("\n------------------------------------------------------");
        printf("\n(ERROR) Fifo is empty");
        printf("\n------------------------------------------------------");
        return FIFO_empty;
    }

    for(i=0;i<FIFO_Buf->count;i++)
    {
        printf("\nStudent number (%d) info: ",i+1);
        printf("\nStudent first name: %s",p_Student->f_name);
        printf("\nStudent last name: %s",p_Student->l_name);
        printf("\nStudent roll number: %d",p_Student->roll_num);
        printf("\nStudent GPA: %f",p_Student->GPA);
        for(j=0;j<COURSE_NUM;j++)
        {
            printf("\nStudent registered course number %d: %d",j,p_Student->course_id[j]);
        }
        printf("\n");
        p_Student++;
    }
}


