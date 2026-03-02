// O(log n)

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int binarySearch(int arr[], int n, int key) {
    int low = 0, high = n - 1;
    while (low <= high) {
        int mid = (low + high) / 2;
        if (arr[mid] == key) return mid;
        else if (arr[mid] < key) low = mid + 1;
        else high = mid - 1;
    }
    return -1;
}

int main() {
    int sizes[] = {1000, 10000, 100000, 1000000};
    clock_t start, end;

    printf("O(log n) - Binary Search\n");
    printf("%-12s %-15s\n", "n", "Time(sec)");
    printf("---------------------------\n");

    for (int i = 0; i < 4; i++) {
        int n = sizes[i];
        int *arr = (int*)malloc(n * sizeof(int));
        for (int j = 0; j < n; j++) arr[j] = j;

        start = clock();
        for (int r = 0; r < 100000; r++)
            binarySearch(arr, n, -1);
        end = clock();

        printf("%-12d %-15f\n", n, (double)(end - start) / CLOCKS_PER_SEC);
        free(arr);
    }
    return 0;
}