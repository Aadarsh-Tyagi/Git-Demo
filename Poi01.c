/*
Take two matrices array in pointers and multiply them
*/

#include <stdio.h>

int main ()
{
    int m, n, p;

    printf("Enter rows and columns of Matrix A: ");
    scanf("%d %d", &m, &n);

    printf("Enter columns of Matrix B: ");
    scanf("%d", &p);

    int A[m][n], B[n][p], C[m][p];

    printf("\nEnter elements of Matrix A:\n");
    for(int i = 0; i < m; i++)
        for(int j = 0; j < n; j++)
            scanf("%d", &A[i][j]);

    printf("\nEnter elements of Matrix B:\n");
    for(int i = 0; i < n; i++)
        for(int j = 0; j < p; j++)
            scanf("%d", &B[i][j]);

    int *ptrA = &A[0][0];
    int *ptrB = &B[0][0];
    int *ptrC = &C[0][0];

    for(int i = 0; i < m; i++) 
    {
        for(int j = 0; j < p; j++) 
        {

            *(ptrC + i*p + j) = 0;

            for(int k = 0; k < n; k++) 
            {
                *(ptrC + i*p + j) += (*(ptrA + i*n + k)) * (*(ptrB + k*p + j));
            }
        }
    }

    printf("\nResult Matrix C:\n");
    for(int i = 0; i < m; i++) 
    {
        for(int j = 0; j < p; j++) 
        {
            printf("%d ", *(ptrC + i*p + j));
        }
        printf("\n");
    }

    return 0;
}