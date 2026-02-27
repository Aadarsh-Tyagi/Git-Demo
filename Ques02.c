// Array Insertion

#include <stdio.h>
#include <time.h>

#define MAX 10000

int arr[MAX];
int n = 5000;

void insert(int pos, int val) {
    for (int i = n; i > pos; i--)
        arr[i] = arr[i - 1];
    arr[pos] = val;
    n++;
}

int main() {
    clock_t start, end;

    for (int i = 0; i < n; i++)
        arr[i] = i + 1;

    start = clock();
    for (int r = 0; r < 1000; r++)
        insert(0, 99);
    end = clock();
    printf("Insert at beginning: %f sec\n", (double)(end - start) / CLOCKS_PER_SEC);

    n = 5000;
    start = clock();
    for (int r = 0; r < 1000; r++)
        insert(n, 99);
    end = clock();
    printf("Insert at end: %f sec\n", (double)(end - start) / CLOCKS_PER_SEC);

    return 0;
}