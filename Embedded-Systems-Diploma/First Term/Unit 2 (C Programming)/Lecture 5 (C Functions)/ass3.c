#include <stdio.h>
#include <string.h>

void reverse ();
void main ()
{
    printf("Enter the text: ");
    reverse();    

}



void reverse (void)
{
    char c;
    scanf("%c",&c);
    if(c!='\n')
    {
        reverse();
        printf("%c",c);
    }
}