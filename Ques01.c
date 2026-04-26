#include <stdio.h>

int main() {
    int m, n;
    scanf("%d %d", &m, &n);

    int mat[m][n];
    for (int i = 0; i < m; i++)
        for (int j = 0; j < n; j++)
            scanf("%d", &mat[i][j]);

    // Step 1: Must be a square matrix
    if (m != n) {
        printf("Not a Symmetric Matrix\n");
        return 0;
    }

    // Step 2: Check mat[i][j] == mat[j][i] for all i, j
    int isSymmetric = 1;
    for (int i = 0; i < m && isSymmetric; i++) {
        for (int j = 0; j < n && isSymmetric; j++) {
            if (mat[i][j] != mat[j][i]) {
                isSymmetric = 0;
            }
        }
    }

    printf("%s\n", isSymmetric ? "Symmetric Matrix" : "Not a Symmetric Matrix");
    return 0;
}