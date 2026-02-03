// Worst Case

#include <stdio.h>
#include <time.h>

int main() {
    int n = 10;
    int arr[10] = {10,9,8,7,6,5,4,3,2,1}; 

    int i, j, key;
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

    printf("Sorted array (Worst Case Input):\n");
    for (i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }

    printf("\nTime taken: %f seconds\n", time_taken);

    return 0;
}
