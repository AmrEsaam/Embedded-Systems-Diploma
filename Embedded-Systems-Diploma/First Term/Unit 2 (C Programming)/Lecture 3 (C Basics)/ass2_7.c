#include <stdio.h>
void main ()
{
    int num=0, i=0;
    long int factorial =1;
    printf("please enter a number: ");
    fflush(stdin);
    scanf("%d",&num);
    if (num<0)
    {
        printf("there's no factorial for negative numbers");
    }

    for (i=num;i>1;i--)
    {
        factorial*=i;
    }
    
    printf("the factorial = %d",factorial);
}