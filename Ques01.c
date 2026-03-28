#include <stdio.h>

int main() {
    int n;
    scanf("%d", &n);

    int arr[n];
    for (int i = 0; i < n; i++)
        scanf("%d", &arr[i]);

    // Two-pointer: i = slow (last unique), j = fast (explorer)
    int i = 0;
    for (int j = 1; j < n; j++) {
        if (arr[j] != arr[i]) {
            i++;
            arr[i] = arr[j];
        }
    }

    // Print unique elements (indices 0 to i)
    for (int k = 0; k <= i; k++) {
        if (k > 0) printf(" ");
        printf("%d", arr[k]);
    }
    printf("\n");

    return 0;
}