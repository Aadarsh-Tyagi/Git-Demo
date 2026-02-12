/*
Matrix Multiplication using Pointers plus functions
*/
#include <stdio.h>

void multiply(int *A, int *B, int *C, int m, int n, int p) 
{

    for(int i = 0; i < m; i++) 
    {
        for(int j = 0; j < p; j++) 
        {

            *(C + i*p + j) = 0;

            for(int k = 0; k < n; k++) 
            {
                *(C + i*p + j) +=  (*(A + i*n + k)) * (*(B + k*p + j));
            }
        }
    }
}

int main() 
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

    multiply(&A[0][0], &B[0][0], &C[0][0], m, n, p);

    printf("\nResult Matrix C:\n");
    for(int i = 0; i < m; i++) 
    {
        for(int j = 0; j < p; j++) 
        {
            printf("%d ", C[i][j]);
        }
        printf("\n");
    }

    return 0;
}
