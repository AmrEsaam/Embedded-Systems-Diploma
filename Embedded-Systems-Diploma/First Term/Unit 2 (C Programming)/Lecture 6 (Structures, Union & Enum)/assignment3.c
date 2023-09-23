#include <stdio.h>

void main (void)
{
    struct num
    {
        float real;
        float img;
    };

    struct num num1,num2;
    float real=0,img=0;

    printf("Enter 1st number");
    printf("\nEnter real part: ");
    scanf("%f",&num1.real);
    fflush(stdin);
    printf("Enter complex part: ");
    scanf("%f",&num1.img);
    fflush(stdin);

    printf("Enter 2nd number");
    printf("\nEnter real part: ");
    scanf("%f",&num2.real);
    printf("Enter complex part: ");
    scanf("%f",&num2.img);

    real= num1.real+num2.real;
    img= num1.img+num2.img;

    
    printf("Sum= %.1f+%.1fi",real,img);
    
}