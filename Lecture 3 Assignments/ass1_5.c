#include <stdio.h>
void main ()
{
    char letter;
    printf("Enter a letter: ");
    scanf("%c",&letter);
    printf("The ASCII value of letter %c is: %d",letter,letter);
}