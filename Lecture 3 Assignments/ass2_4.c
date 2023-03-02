#include <stdio.h>
void main ()
{
    signed int num=0;
    printf("Please Enter a Number: ");
    fflush(stdin);
    scanf("%d",&num);
    int bit= (num >> 7) & 1;
    if (bit==0)
    {
        printf("The number is positive");
    }
    else
    {
        printf("The number is negative");
    }

}