/*
 * main.c
 *
 *  Created on: Sep 12, 2023
 *      Author: Amr
 */
#include"linked_list.h"

#define DPRINTF(...) {fflush(stdout);\
                     fflush(stdin);\
                     printf(__VA_ARGS__);\
                     fflush(stdout);\
                     fflush(stdin);}

int main(void)
{
    while(1)
    {
        char option[10];
        DPRINTF("\n________________________________________");
        DPRINTF("\nEnter the required operation: ");
        DPRINTF("\n(1) Add student ");
        DPRINTF("\n(2) Delete student ");
        DPRINTF("\n(3) View all students ");
        DPRINTF("\n(4) Delete all students ");
        DPRINTF("\n(5) Get a specific student ");
        DPRINTF("\n(6) Get the length of the list ");
        DPRINTF("\n(7) Get a specific student from the end ");
        DPRINTF("\n(8) Get the middle student ");
        DPRINTF("\n(9) Check if the list is looped ");
        DPRINTF("\n(10) Reverse the list ");
        DPRINTF("\n________________________________________\n");

        gets(option);

        switch (atoi(option))
        {
        case 1:
            AddNode();
            break;

        case 2:
            DeleteNode();
            break;

        case 3:
            PrintAll();
            break;

        case 4:
            DeleteAll();
            break;

        case 5:
            GetNth();
            break;
        
        case 6:
            printf("\nThe number of nodes in the list = %d",GetLength());
            break;

        case 7:
            GetNthEnd();
            break;

        case 8:
            GetMiddle();
            break;

        case 9:
            DetectLoop();
            break;

        case 10:
            ReverseList();
            break;
    
        default:
            DPRINTF("\nError: No Valid Choice Is Entered");
            break;
        }

    }
    return 0;
}
