#include <stdio.h>
#include <string.h>

void main ()
{
    int i=0, counter=0;
    char text[100];
    
    printf("Enter the string: ");
    fflush(stdin);
    gets(text);

    

    for(i=0;text[i]!='\0';i++)
    {
        counter++;
    }

    printf("The length of the entered text= %d",counter);
    



}