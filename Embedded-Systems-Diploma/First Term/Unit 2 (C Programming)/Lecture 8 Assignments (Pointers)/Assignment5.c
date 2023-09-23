#include <stdio.h>

void main (void)
{
    char i=0;
    struct emp
    {
        char *name;
        char id;
    };
    
    struct emp emp1={"Amr",1}, emp2={"Hazem",2}, emp3={"Ahmed",3};
    struct emp *arr[3]={&emp1, &emp2, &emp3};
    struct emp *ptr =&emp1;

    printf("Employees data\n");
    for(i=0;i<3;i++)
    {
        printf("\nEmp%d name is: %s",i+1,(ptr+i)->name);
        printf("\nEmp%d id is: %d",i+1,(ptr+i)->id);
    }
}