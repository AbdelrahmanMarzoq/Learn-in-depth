#include <stdio.h>
#include <stdlib.h>
#include <string.h>



int main()
{
    int row, column;
    int matrix[100][100];
    int transpose[100][100];

    printf("Enter rows and column of matrix: ");
    scanf("%d",&row);
    scanf("%d",&column);
    for (int i = 0; i < row; i++)
    {
        for (int j = 0 ; j < column; j++)
        {
            printf("Enter element of a%d%d: ",(i+1),(j+1));
            scanf("%d",&matrix[i][j]);
        }
    }
    printf("Entered Matrix:\n");
    for (int i = 0; i < row; i++)
    {
        for (int j = 0 ; j < column; j++)
        {
            printf("%d\t",matrix[i][j]);
        }
        printf("\n");
    }
    printf("Transpose of Matrix:\n");

    for (int i = 0; i < column; i++)
    {
        for (int j = 0 ; j < row; j++)
        {
            transpose[i][j] = matrix[j][i];
        }
        printf("\n");
    }

    for (int i = 0; i < column; i++)
    {
        for (int j = 0 ; j < row; j++)
        {
            printf("%d\t",transpose[i][j]);
        }
        printf("\n");
    }
    return 0;
}




