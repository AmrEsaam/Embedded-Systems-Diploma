#include "student_fifo.h"


int main(void)
{
    int choice=0;
    element_type Arr_Buffer[buffer_length];
    FIFO_Buffer_t Buf;
    FIFO_Init(&Buf,Arr_Buffer,buffer_length);
    printf("\n------------------------------------------------------");
    printf("\n----------Welcome to School Management System---------");
    printf("\n------------------------------------------------------");
    printf("\n");

    while(1)
    {
        printf("\n------------------------------------------------------");
        printf("\nChoose one of the following options: ");
        printf("\n1- Add student manually ");
        printf("\n2- Add student from file ");
        printf("\n3- Find student by roll number ");
        printf("\n4- Find student by first name ");
        printf("\n5- Find student by course id ");
        printf("\n6- Count students ");
        printf("\n7- Delete a student by roll number ");
        printf("\n8- Update a student by roll number ");
        printf("\n9- Show all students' information ");
        printf("\n10- Exit ");
        printf("\n------------------------------------------------------");
        printf("\n\nChoose: ");

        scanf("%d",&choice);

        switch (choice)
        {
        case 1:
            FIFO_add_student(&Buf);
            break;
        
        case 2:
            FIFO_add_student_file(&Buf);
            break;

        case 3:
            FIFO_find_roll_num(&Buf);
            break;

        case 4:
            FIFO_find_first_name(&Buf);
            break;

        case 5:
            FIFO_find_course(&Buf);
            break;

        case 6:
            FIFO_count(&Buf);
            break;

        case 7:
            FIFO_delete_student(&Buf);
            break;

        case 8:
            FIFO_update_student(&Buf);
            break;

        case 9:
            FIFO_show_info(&Buf);
            break;

        case 10:
            return 0;
            break;
        
        default:
            printf("\n------------------------------------------------------");
            printf("\n(ERROR! Wrong Choice)");
            printf("\n------------------------------------------------------");
            break;
        }

    }
    return 0;
}