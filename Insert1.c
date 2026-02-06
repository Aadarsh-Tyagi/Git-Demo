// Insertion at any given position

#include <stdio.h>

int main() 
{
    int arr[100], n, i, element, index;

    printf("Enter number of elements: ");
    scanf("%d", &n);

    printf("Enter %d elements:\n", n);
    for(i = 0; i < n; i++) 
    {
        scanf("%d", &arr[i]);
    }

    printf("Enter index (0 to %d): ", n);
    scanf("%d", &index);

    if(index < 0 || index > n) 
    {
        printf("Invalid index!");
        return 0;
    }

    printf("Enter element to insert: ");
    scanf("%d", &element);

    for(i = n; i > index; i--) 
    {
        arr[i] = arr[i - 1];
    }

    arr[index] = element;
    n++;

    printf("Updated array:\n");
    for(i = 0; i < n; i++) 
    {
        printf("%d ", arr[i]);
    }

    return 0;
}
