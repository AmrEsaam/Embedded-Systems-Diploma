#include <stdio.h>
#include <string.h>

void main ()
{
    int i=0, counter=0;
    char character;
    char text[100];
    
    printf("Enter the string: ");
    fflush(stdin);
    gets(text);

    printf("Enter the character: ");
    fflush(stdin);
    scanf("%c",&character);

    for(i=0;i<strlen(text);i++)
    {
        if(character==text[i])
        {
            counter++;
        }
    }

    printf("The letter %c is repeated for %d times",character,counter);
    



}