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

void delete(int pos) {
    for (int i = pos; i < n - 1; i++)
        arr[i] = arr[i + 1];
    n--;
}

void traversal() {
    for (int i = 0; i < n; i++)
        printf("%d ", arr[i]);
    printf("\n");
}

int main() {
    clock_t start, end;

    for (int i = 0; i < n; i++)
        arr[i] = i + 1;

    start = clock();
    traversal();
    end = clock();
    printf("Traversal time: %f sec\n\n", (double)(end - start) / CLOCKS_PER_SEC);

    start = clock();
    for (int r = 0; r < 1000; r++)
        insert(0, 99);
    end = clock();
    printf("Insertion at beginning time: %f sec\n\n", (double)(end - start) / CLOCKS_PER_SEC);

    n = 5000;
    start = clock();
    for (int r = 0; r < 1000; r++)
        insert(n, 99);
    end = clock();
    printf("Insertion at end time: %f sec\n\n", (double)(end - start) / CLOCKS_PER_SEC);

    n = 5000;
    start = clock();
    for (int r = 0; r < 1000; r++)
        delete(0);
    end = clock();
    printf("Deletion at beginning time: %f sec\n\n", (double)(end - start) / CLOCKS_PER_SEC);

    n = 5000;
    start = clock();
    for (int r = 0; r < 1000; r++)
        delete(n - 1);
    end = clock();
    printf("Deletion at end time: %f sec\n\n", (double)(end - start) / CLOCKS_PER_SEC);

    return 0;
}