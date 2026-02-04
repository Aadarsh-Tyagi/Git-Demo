#include <stdio.h>

int main() {
    int arr[100];
    int n, i, pos, value;
    int j, temp;

    printf("Enter number of elements: ");
    scanf("%d", &n);

    printf("Enter elements:\n");
    for(i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    printf("Enter position to insert: ");
    scanf("%d", &pos);

    printf("Enter value to insert: ");
    scanf("%d", &value);

    // make space
    for(i = n; i >= pos; i--) {
        arr[i] = arr[i - 1];
    }

    // insert value
    arr[pos - 1] = value;
    n++;

    // sort array (simple bubble sort)
    for(i = 0; i < n - 1; i++) {
        for(j = 0; j < n - 1; j++) {
            if(arr[j] > arr[j + 1]) {
                temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }

    printf("Array after insertion and sorting:\n");
    for(i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }

    return 0;
}