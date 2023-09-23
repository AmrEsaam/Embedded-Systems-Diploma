#include <stdio.h>

void main (void)
{
    int m=29;
    int *pm=&m, *ab=NULL;
    printf("The address of m= 0x%x",pm);
    printf("\nThe value of m= %d",m);

    ab=pm;
    printf("\nThe address of ab= 0x%x",ab);
    printf("\nThe value of ab= %d",*ab);

    m=34;
    printf("\nThe address of ab= 0x%x",ab);
    printf("\nThe value of ab= %d",*ab);

    *ab=7;
    printf("\nThe address of m= 0x%x",pm);
    printf("\nThe value of m= %d",m);


}