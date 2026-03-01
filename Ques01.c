// Array Traversal

#include <stdio.h>
#include <time.h>

int main() {
    int n = 5000;
    int arr[5000];
    clock_t start, end;

    for (int i = 0; i < n; i++)
        arr[i] = i + 1;

    start = clock();
    for (int i = 0; i < n; i++)
        printf("%d ", arr[i]);
    end = clock();

    printf("\nTime: %f sec\n", (double)(end - start) / CLOCKS_PER_SEC);
    return 0;
}