#include <stdio.h>
void main ()
{
    int sum=0, num=0, i=0;
    printf("Please Enter a Number: ");
    fflush(stdin);
    scanf("%d",&num);
    
    for (i=num;i>0;i--)
    {
        sum+=i;
    }

    printf("Sum = %d",sum);
}