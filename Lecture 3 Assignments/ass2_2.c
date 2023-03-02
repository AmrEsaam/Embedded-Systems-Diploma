#include <stdio.h>
void main ()
{
    char letter;
    printf("Please Enter a Letter: ");
    fflush(stdin);
    scanf("%c",&letter);
    if (letter=='a'||letter=='e' || letter=='i' || letter=='o'|| letter=='u')
    {
        printf("The Letter is Vowel");
    }
    else
    {
        printf("The Letter is Constant");
    }

}