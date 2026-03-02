// O(1)

#include <stdio.h>
#include <time.h>

int getElement(int arr[], int index) {
    return arr[index];
}

int main() {
    int arr[] = {10, 20, 30, 40, 50};
    clock_t start, end;

    start = clock();
    for (int r = 0; r < 1000000; r++)
        getElement(arr, 3);
    end = clock();

    printf("O(1) - Array Access\n");
    printf("n = fixed, Time = %f sec\n", (double)(end - start) / CLOCKS_PER_SEC);
    return 0;
}