// O(n)

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int linearSearch(int arr[], int n, int key) {
    for (int i = 0; i < n; i++)
        if (arr[i] == key) return i;
    return -1;
}

int main() {
    int sizes[] = {1000, 5000, 10000, 50000};
    clock_t start, end;

    printf("O(n) - Linear Search\n");
    printf("%-12s %-15s\n", "n", "Time(sec)");
    printf("---------------------------\n");

    for (int i = 0; i < 4; i++) {
        int n = sizes[i];
        int *arr = (int*)malloc(n * sizeof(int));
        for (int j = 0; j < n; j++) arr[j] = j;

        start = clock();
        for (int r = 0; r < 1000; r++)
            linearSearch(arr, n, -1);
        end = clock();

        printf("%-12d %-15f\n", n, (double)(end - start) / CLOCKS_PER_SEC);
        free(arr);
    }
    return 0;
}