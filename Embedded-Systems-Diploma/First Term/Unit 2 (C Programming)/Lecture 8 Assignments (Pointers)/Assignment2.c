#include <stdio.h>

void main (void)
{
    int i=0;
    char ch;
    char *ptr=&ch;
    *ptr='A';

    printf("The alphabets are: \n");
    for(i=0;i<26;i++)
    {
        printf("%c ",*ptr+i);
    }

}