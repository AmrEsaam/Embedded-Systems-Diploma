#include <stdio.h>
#include <string.h>

void main ()
{
    int i=0, counter=0;
    char text[100];
    char new_text[100];
    
    printf("Enter the string: ");
    fflush(stdin);
    gets(text);


    for(i=0;i<strlen(text);i++)
    {
        new_text[strlen(text)-i]=text[i];
    }

    printf("The reversed text is: %s",new_text);
    
}