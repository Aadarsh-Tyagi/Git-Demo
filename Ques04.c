// O(n log n)

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void merge(int arr[], int l, int m, int r) {
    int n1 = m - l + 1, n2 = r - m;
    int L[n1], R[n2];
    for (int i = 0; i < n1; i++) L[i] = arr[l + i];
    for (int j = 0; j < n2; j++) R[j] = arr[m + 1 + j];
    int i = 0, j = 0, k = l;
    while (i < n1 && j < n2)
        arr[k++] = (L[i] <= R[j]) ? L[i++] : R[j++];
    while (i < n1) arr[k++] = L[i++];
    while (j < n2) arr[k++] = R[j++];
}

void mergeSort(int arr[], int l, int r) {
    if (l < r) {
        int m = (l + r) / 2;
        mergeSort(arr, l, m);
        mergeSort(arr, m + 1, r);
        merge(arr, l, m, r);
    }
}

int main() {
    int sizes[] = {1000, 5000, 10000, 50000};
    clock_t start, end;

    printf("O(n log n) - Merge Sort\n");
    printf("%-12s %-15s\n", "n", "Time(sec)");
    printf("---------------------------\n");

    for (int i = 0; i < 4; i++) {
        int n = sizes[i];
        int *arr = (int*)malloc(n * sizeof(int));
        for (int j = 0; j < n; j++) arr[j] = n - j;

        start = clock();
        mergeSort(arr, 0, n - 1);
        end = clock();

        printf("%-12d %-15f\n", n, (double)(end - start) / CLOCKS_PER_SEC);
        free(arr);
    }
    return 0;
}