// O(2^n)

#include <stdio.h>
#include <time.h>

long long fib(int n) {
    if (n <= 1) return n;
    return fib(n - 1) + fib(n - 2);
}

int main() {
    int sizes[] = {10, 20, 30, 40};
    clock_t start, end;

    printf("O(2^n) - Recursive Fibonacci\n");
    printf("%-12s %-15s %-15s\n", "n", "fib(n)", "Time(sec)");
    printf("------------------------------------------\n");

    for (int i = 0; i < 4; i++) {
        int n = sizes[i];
        start = clock();
        long long result = fib(n);
        end = clock();

        printf("%-12d %-15lld %-15f\n", n, result, (double)(end - start) / CLOCKS_PER_SEC);
    }

    printf("\nWARNING: Do NOT try n > 50, it will hang!!\n");
    return 0;
}