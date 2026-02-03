// Insertion Sort 

#include <stdio.h>
#include <time.h>

int main() {
    int n, i, j, key;

    printf("Enter number of elements: ");
    scanf("%d", &n);

    int arr[n];

    printf("Enter %d elements:\n", n);
    for (i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    clock_t start, end;
    double time_taken;

    start = clock();   

    
    for (i = 1; i < n; i++) {
        key = arr[i];
        j = i - 1;

        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = key;
    }

    end = clock();    

    time_taken = (double)(end - start) / CLOCKS_PER_SEC;

    printf("Sorted array:\n");
    for (i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }

    printf("\nTime taken: %f seconds\n", time_taken);

    return 0;
}
