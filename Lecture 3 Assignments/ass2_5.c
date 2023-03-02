#include <stdio.h>
void main ()
{
    char letter;
    printf("Please Enter a Letter: ");
    fflush(stdin);
    scanf("%c",&letter);
    if ((letter >= 'a' && letter <= 'z') || (letter >= 'A' && letter <= 'Z'))
    {
        printf("It's a Letter");
    }
    else
    {
        printf("It's not a Letter");
    }

}