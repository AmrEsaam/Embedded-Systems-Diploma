#include <stdio.h>

void main (void)
{
    int i=0, j=0;
   char str[]="w3resource";
   char *ptr=str;

    for(i=0;i<50;i++)
    {
        if(*(ptr+i)=='\0')
        {
            j=i;
            break;
        }
    }

    for(j;j>=0;j--)
    {
        printf("%c",*(ptr+j));
    }

}