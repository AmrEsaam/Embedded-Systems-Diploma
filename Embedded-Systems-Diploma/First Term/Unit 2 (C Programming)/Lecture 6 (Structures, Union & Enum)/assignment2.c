#include <stdio.h>

void main (void)
{
    struct distance
    {
        int feet;
        float inch;
    };

    struct distance distance1,distance2;
    float inch=0;
    int feet=0;

    printf("Enter information for 1st distance");
    printf("\nEnter feet: ");
    scanf("%d",&distance1.feet);
    printf("Enter inches: ");
    scanf("%f",&distance1.inch);
    fflush(stdin);
    printf("Enter information for 2nd distance");
    printf("\nEnter feet: ");
    scanf("%d",&distance2.feet);
    printf("Enter inches: ");
    scanf("%f",&distance2.inch);

    feet= distance1.feet+distance2.feet;
    inch= distance1.inch+distance2.inch;

    if (inch>=12)
    {
        feet+=1;
        inch=12-inch;
    }
    
    printf("Sum of distances= %d' %.1f\"",feet,inch);
    
}