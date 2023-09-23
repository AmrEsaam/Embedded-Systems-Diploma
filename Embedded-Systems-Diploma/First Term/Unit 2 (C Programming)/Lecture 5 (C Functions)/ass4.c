#include <stdio.h>
#include <string.h>

int power (int n, int p);
void main ()
{
    int n=0, p=0;
    printf("Enter the base number: ");
    scanf("%d",&n);
    printf("Enter the power number: ");
    scanf("%d",&p);
    printf("The answer= %d",power(n,p));

}



int power (int n, int p)
{
    if(p>0)
    {
        p--;
        return (n*power(n,p));
    }
    else
    {
        return 1;
    }
}