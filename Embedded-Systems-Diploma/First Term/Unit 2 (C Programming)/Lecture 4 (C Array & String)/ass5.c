#include <stdio.h>
void main ()
{
    int n=0, i=0, element=0, location=0;
    int arr[10];
    
    printf("Enter the number of elements: ");
    fflush(stdin);
    scanf("%d",&n);

    for(i=0;i<n;i++)
    {
        arr[i]=i+1;
    }

    printf("Enter the required element: ");
    fflush(stdin);
    scanf("%d",&element);

    for(i=0;i<n;i++)
    {
        if(element==arr[i])
        {
            printf("The location of required element= %d",i+1);
        }
    }



}