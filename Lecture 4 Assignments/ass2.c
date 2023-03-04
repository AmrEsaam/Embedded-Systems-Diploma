#include <stdio.h>
void main ()
{
    int i=0, n=0;
    int sum=0, avg=0;
    int arr[10];

    printf("Enter the number of Data: \n");
    scanf("%d",&n);

    for(i=0;i<n;i++)
    {
        printf("Enter the element arr[%d]: \n",i);
        fflush(stdin);
        scanf("%d",&arr[i]);
    }

    for(i=0;i<n;i++)
    {
        sum+=arr[i];
    }

    
    avg=sum/n;
    printf("The average of entered data= %d",avg);

    
}