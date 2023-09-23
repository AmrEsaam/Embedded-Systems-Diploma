#include <stdio.h>
void main ()
{
    int row=0, col=0, nrow=0, ncol=0;
    int arr[5][5];
    int transpose[5][5];

    printf("Enter the number of rows: ");
    fflush(stdin);
    scanf("%d",&nrow);
    printf("Enter the number of coloumns: ");
    fflush(stdin);
    scanf("%d",&ncol);

    for(row=0;row<nrow;row++)
    {
        for(col=0;col<ncol;col++)
        {
            printf("Enter the element of arr[%d][%d]: ",row,col);
            fflush(stdin);
            scanf("%d",&arr[row][col]);
        }
    }

    for(row=0;row<nrow;row++)
    {
        for(col=0;col<ncol;col++)
        {
            transpose[row][col]=arr[col][row];
        }
    }


    for(row=0;row<nrow;row++)
    {
        for(col=0;col<ncol;col++)
        {
            printf("%d\t",transpose[row][col]);
        }
        printf("\n");
    }


    

    
}