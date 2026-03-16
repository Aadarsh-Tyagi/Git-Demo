#include <stdio.h>
#include <time.h>

int main() {
    int arr[] = {64, 25, 12, 22, 11, 90, 45, 33, 78, 55};
    int n = 10;
    clock_t start, end;

    start = clock();
    for (int i = 1; i < n; i++) {
        int key = arr[i];
        int j = i - 1;
        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = key;
    }
    end = clock();

    for (int i = 0; i < n; i++)
        printf("%d ", arr[i]);
    printf("\nTime: %f sec\n", (double)(end - start) / CLOCKS_PER_SEC);
    return 0;
}