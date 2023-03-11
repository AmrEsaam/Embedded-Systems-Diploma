#include <stdio.h>
#include <string.h>

int factorial (int num);
void main ()
{
    int num=0;
    
    printf("Enter the number: ");
    fflush(stdin);
    scanf("%d",&num);

    printf("the factorial of %d = %d",num,factorial(num));

    
}

int factorial (int num)
{
    int counter=num;
    if (num>=1)
    {
    return num*factorial(num-1);
    }
    else
    {
    return 1;
    }
    counter--;
}