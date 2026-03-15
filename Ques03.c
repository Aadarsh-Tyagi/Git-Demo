// Array Deletion

#include <stdio.h>
#include <time.h>

#define MAX 10000

int arr[MAX];
int n = 5000;

void delete(int pos) {
    for (int i = pos; i < n - 1; i++)
        arr[i] = arr[i + 1];
    n--;
}

int main() {
    clock_t start, end;

    for (int i = 0; i < n; i++)
        arr[i] = i + 1;

    start = clock();
    for (int r = 0; r < 1000; r++)
        delete(0);
    end = clock();
    printf("Delete at beginning: %f sec\n", (double)(end - start) / CLOCKS_PER_SEC);

    n = 5000;
    start = clock();
    for (int r = 0; r < 1000; r++)
        delete(n - 1);
    end = clock();
    printf("Delete at end: %f sec\n", (double)(end - start) / CLOCKS_PER_SEC);

    return 0;
}