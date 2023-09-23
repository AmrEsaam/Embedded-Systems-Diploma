#include <stdio.h>
#define area(radius) 3.14159265359*radius*radius

void main (void)
{
    float radius=0;
    printf("Please enter the radius: ");
   scanf("%f",&radius);
    printf("The area of circle= %.2f",area(radius));
}