#include <stdio.h>
void main ()
{
    int num=0;
    printf("Please Enter a Number: ");
    fflush(stdin);
    scanf("%d",&num);
    if (num%2==0)
    {
        printf("The number is even");
    }
    else
    {
        printf("The number is odd");
    }

}