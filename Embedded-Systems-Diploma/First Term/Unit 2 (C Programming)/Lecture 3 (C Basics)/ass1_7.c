#include <stdio.h>
void main ()
{
    int a=0, b=0;
    int *pa=&a;
    int *pb=&b;
    printf("Enter the first number ");
    scanf("%d",&a);
    printf("Enter the second number ");
    scanf("%d",&b);

    

    printf("Enter the first number after swapping= %d\n",a);
    printf("Enter the second number after swapping= %d",b);

}