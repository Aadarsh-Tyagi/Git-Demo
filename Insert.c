// Insertion in the beginning 

#include <stdio.h>

int main() 
{
    int arr[100], n, i, element;

    printf("Enter number of elements: ");
    scanf("%d", &n);

    printf("Enter %d elements:\n", n);
    for(i = 0; i < n; i++) 
    {
        scanf("%d", &arr[i]);
    }

    printf("Enter element to insert at beginning: ");
    scanf("%d", &element);

    for(i = n; i > 0; i--) 
    {
        arr[i] = arr[i - 1];
    }

    arr[0] = element;
    n++;

    printf("Updated array:\n");
    for(i = 0; i < n; i++) 
    {
        printf("%d ", arr[i]);
    }

    return 0;
}
