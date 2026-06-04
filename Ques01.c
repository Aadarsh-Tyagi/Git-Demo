#include <stdio.h>

int main() {
    int r, c;
    scanf("%d %d", &r, &c);

    int mat[r][c];
    for (int i = 0; i < r; i++)
        for (int j = 0; j < c; j++)
            scanf("%d", &mat[i][j]);

    int top = 0, bottom = r - 1, left = 0, right = c - 1;
    int first = 1;

    while (top <= bottom && left <= right) {

        // Move right across top row
        for (int j = left; j <= right; j++) {
            if (!first) printf(" ");
            printf("%d", mat[top][j]);
            first = 0;
        }
        top++;

        // Move down right column
        for (int i = top; i <= bottom; i++) {
            if (!first) printf(" ");
            printf("%d", mat[i][right]);
            first = 0;
        }
        right--;

        // Move left across bottom row (if rows remain)
        if (top <= bottom) {
            for (int j = right; j >= left; j--) {
                if (!first) printf(" ");
                printf("%d", mat[bottom][j]);
                first = 0;
            }
            bottom--;
        }

        // Move up left column (if columns remain)
        if (left <= right) {
            for (int i = bottom; i >= top; i--) {
                if (!first) printf(" ");
                printf("%d", mat[i][left]);
                first = 0;
            }
            left++;
        }
    }

    printf("\n");
    return 0;
}