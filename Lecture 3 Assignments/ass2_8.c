#include <stdio.h>
void main ()
{
    int num1=0, num2=0, result=0;
    char operation;

    printf("please choose the operation (+) or (-) or (*) or (-)\n");
    fflush(stdin);
    scanf("%c",&operation);
    printf("please choose the two operands: ");
    fflush(stdin);
    scanf("%d",&num1);
    scanf("%d",&num2);

    switch (operation)
    {
        case '+':
        result=num1+num2;
        printf("The Result= %d",result);
        break;

        case '-':
        result=num1-num2;
        printf("The Result= %d",result);
        break;

        case '*':
        result=num1*num2;
        printf("The Result= %d",result);
        break;

        case '/':
        result=num1/num2;
        printf("The Result= %d",result);
        break;

        default:
        printf("Wrong Operation");
    }

    
}