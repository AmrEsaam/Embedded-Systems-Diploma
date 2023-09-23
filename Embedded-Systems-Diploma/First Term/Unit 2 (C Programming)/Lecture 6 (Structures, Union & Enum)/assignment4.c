#include <stdio.h>

void main (void)
{
    int i=0;

    struct student
    {
        char name[50];
        int roll;
        int marks;
    };

    struct student data[10];

    for(i=0;i<=9;i++)
    {
        printf("Student no. %d data",i+1);
        printf("\nEnter the student name: ");
        gets(data[i].name);
        printf("Enter the student roll number: ");
        scanf("%d",&data[i].roll);
        printf("Enter the student marks: ");
        scanf("%d",&data[i].marks);
        fflush(stdin);
    }

   
    for(i=0;i<=9;i++)
    {
        printf("student name: %s\n",data[i].name);
        printf("student roll: %d\n",data[i].roll);
        printf("student marks: %d\n",data[i].marks);
    }

    
}