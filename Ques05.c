// O(n^2)

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void bubbleSort(int arr[], int n) {
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n - i - 1; j++)
            if (arr[j] > arr[j + 1]) {
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
}

int main() {
    int sizes[] = {500, 1000, 2000, 4000};
    clock_t start, end;

    printf("O(n^2) - Bubble Sort\n");
    printf("%-12s %-15s\n", "n", "Time(sec)");
    printf("---------------------------\n");

    for (int i = 0; i < 4; i++) {
        int n = sizes[i];
        int *arr = (int*)malloc(n * sizeof(int));
        for (int j = 0; j < n; j++) arr[j] = n - j;

        start = clock();
        bubbleSort(arr, n);
        end = clock();

        printf("%-12d %-15f\n", n, (double)(end - start) / CLOCKS_PER_SEC);
        free(arr);
    }
    return 0;
}