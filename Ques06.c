// O(n^3)

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void matMul(int n) {
    int **A = (int**)malloc(n * sizeof(int*));
    int **B = (int**)malloc(n * sizeof(int*));
    int **C = (int**)malloc(n * sizeof(int*));
    for (int i = 0; i < n; i++) {
        A[i] = (int*)malloc(n * sizeof(int));
        B[i] = (int*)malloc(n * sizeof(int));
        C[i] = (int*)calloc(n, sizeof(int));
        for (int j = 0; j < n; j++) { A[i][j] = 1; B[i][j] = 1; }
    }

    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            for (int k = 0; k < n; k++)
                C[i][j] += A[i][k] * B[k][j];

    for (int i = 0; i < n; i++) { free(A[i]); free(B[i]); free(C[i]); }
    free(A); free(B); free(C);
}

int main() {
    int sizes[] = {50, 100, 200, 300};
    clock_t start, end;

    printf("O(n^3) - Matrix Multiplication\n");
    printf("%-12s %-15s\n", "n", "Time(sec)");
    printf("---------------------------\n");

    for (int i = 0; i < 4; i++) {
        int n = sizes[i];
        start = clock();
        matMul(n);
        end = clock();

        printf("%-12d %-15f\n", n, (double)(end - start) / CLOCKS_PER_SEC);
    }
    return 0;
}