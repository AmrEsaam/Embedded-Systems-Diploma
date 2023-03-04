#include <stdio.h>
void main ()
{
    int row=0, col=0;
    int arr1[2][2];
    int arr2[2][2];
    int sum_arr[2][2];

    for(row=0;row<2;row++)
    {
        for(col=0;col<2;col++)
        {
            printf("Enter the element of arr1[%d][%d]: ",row,col);
            fflush(stdin);
            scanf("%d",&arr1[row][col]);
        }
    }

    for(row=0;row<2;row++)
    {
        for(col=0;col<2;col++)
        {
            printf("Enter the element of arr2[%d][%d]: ",row,col);
            fflush(stdin);
            scanf("%d",&arr2[row][col]);
        }
    }

    for(row=0;row<2;row++)
    {
        for(col=0;col<2;col++)
        {
            sum_arr[row][col]= arr1[row][col] + arr2[row][col];
        }
    }

    for(row=0;row<2;row++)
    {
        for(col=0;col<2;col++)
        {
            printf("%d\t",sum_arr[row][col]);
        }
        printf("\n");
    }


    

    
}