// Implement reverse an array using stack

#include <stdio.h>

#define MAX 100

void reverseArray(int arr[], int n) {
    int stack[MAX];
    int top = -1;

    for (int i = 0; i < n; i++) {
        stack[++top] = arr[i];
    }

    for (int i = 0; i < n; i++) {
        arr[i] = stack[top--];
    }
}

int main() {
    int arr[] = {10, 20, 30, 40};
    int n = 4;

    reverseArray(arr, n);

    printf("Reversed array: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }

    return 0;
}