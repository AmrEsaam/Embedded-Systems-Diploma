#include <stdio.h>

void main (void)
{
    int i=0, j=0, n=0;
   int arr[15];
   int *ptr=arr;

    printf("Enter number of array elements: ");
    scanf("%d",&n);

    for(i=0;i<n;i++)
    {
        printf("Enter the elemet- %d: ",i+1);
        scanf("%d",ptr+i);
    }

    j=i;

    for(j;j>0;j--)
    {
        printf("element -%d = %d \n",j,*(ptr+j-1));
    }

}