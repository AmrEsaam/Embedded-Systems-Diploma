#include <stdio.h>
#include <string.h>

void prime_num (void);
void main ()
{
    prime_num();
}

void prime_num (void)
{
    int i=0,j=0, num_1=0, num_2=0;
    int num=0, flag=0, m=0;
    int diff= num_1-num_2;
    printf("Enter the first number: ");
    fflush(stdin);
    scanf("%d",&num_1);
    printf("Enter the second number: ");
    fflush(stdin);
    scanf("%d",&num_2);

    m=num/2;

    num=num_1;
    for(i=num_1;i<num_2;i++)
    {
        for(j=2;j<m;j++)
        {
            if((num+i)%2==0)
            {
                flag=1;
            }
        }

        if(flag==0)
        {
            printf("%d\t",(num+i));
        }
    }
}