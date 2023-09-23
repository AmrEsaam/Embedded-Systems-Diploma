#include <stdio.h>
void main ()
{
    int a=0, b=0, temp=0;
    printf("Enter the first number ");
    scanf("%d",&a);
    printf("Enter the second number ");
    scanf("%d",&b);

    temp=a;
    a=b;
    b=temp;

    printf("Enter the first number after swapping= %d\n",a);
    printf("Enter the second number after swapping= %d",b);

}