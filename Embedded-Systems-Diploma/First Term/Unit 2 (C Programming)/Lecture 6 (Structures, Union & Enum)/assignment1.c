#include <stdio.h>

void main (void)
{
    struct student
    {
        char name[50];
        int roll;
        int marks;
    };

    struct student student1;

    printf("Enter the student name: ");
    gets(student1.name);
    printf("Enter the student roll number: ");
    scanf("%d",&student1.roll);
    printf("Enter the student marks: ");
    scanf("%d",&student1.marks);

    printf("student name: %s\n",student1.name);
    printf("student roll: %d\n",student1.roll);
    printf("student marks: %d\n",student1.marks);

    
}