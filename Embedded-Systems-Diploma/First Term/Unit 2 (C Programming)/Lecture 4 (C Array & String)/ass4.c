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

    printf("Enter the inserted element: ");
    fflush(stdin);
    scanf("%d",&element);

    printf("Enter the location of inserted element: ");
    fflush(stdin);
    scanf("%d",&location);

    arr[location-1]=element;

    for(i=0;i<n;i++)
    {
    printf("%d\t",arr[i]);
    }



}