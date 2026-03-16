#include <stdio.h>
#include <stdlib.h>

void inputMatrix(int **mat, int r, int c) {
    for (int i = 0; i < r; i++)
        for (int j = 0; j < c; j++)
            scanf("%d", (*(mat + i) + j));
}

void printMatrix(int **mat, int r, int c) {
    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++)
            printf("%5d ", *(*(mat + i) + j));
        printf("\n");
    }
}

void addMatrix(int **A, int **B, int **C, int r, int c) {
    for (int i = 0; i < r; i++)
        for (int j = 0; j < c; j++)
            *(*(C + i) + j) = *(*(A + i) + j) + *(*(B + i) + j);
}

void subMatrix(int **A, int **B, int **C, int r, int c) {
    for (int i = 0; i < r; i++)
        for (int j = 0; j < c; j++)
            *(*(C + i) + j) = *(*(A + i) + j) - *(*(B + i) + j);
}

void mulMatrix(int **A, int **B, int **C, int r1, int c1, int c2) {
    for (int i = 0; i < r1; i++)
        for (int j = 0; j < c2; j++) {
            *(*(C + i) + j) = 0;
            for (int k = 0; k < c1; k++)
                *(*(C + i) + j) += *(*(A + i) + k) * *(*(B + k) + j);
        }
}

int** allocMatrix(int r, int c) {
    int **mat = (int **)malloc(r * sizeof(int *));
    for (int i = 0; i < r; i++)
        *(mat + i) = (int *)calloc(c, sizeof(int));
    return mat;
}

void freeMatrix(int **mat, int r) {
    for (int i = 0; i < r; i++)
        free(*(mat + i));
    free(mat);
}

int main() {
    int r, c;
    scanf("%d %d", &r, &c);

    int **A = allocMatrix(r, c);
    int **B = allocMatrix(r, c);
    int **C = allocMatrix(r, c);

    inputMatrix(A, r, c);
    inputMatrix(B, r, c);

    printMatrix(A, r, c);
    printf("\n");
    printMatrix(B, r, c);

    printf("\n");
    addMatrix(A, B, C, r, c);
    printMatrix(C, r, c);

    printf("\n");
    subMatrix(A, B, C, r, c);
    printMatrix(C, r, c);

    printf("\n");
    freeMatrix(C, r);
    C = allocMatrix(r, c);
    mulMatrix(A, B, C, r, c, c);
    printMatrix(C, r, c);

    freeMatrix(A, r);
    freeMatrix(B, r);
    freeMatrix(C, r);

    return 0;
}