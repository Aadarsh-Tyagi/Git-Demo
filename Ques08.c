// Print Linked List elements

#include <stdio.h>
#include <stdlib.h>

struct Node 
{
    int data;
    struct Node* next;
};

struct Node* newNode(int val) 
{
    struct Node* node = (struct Node*)malloc(sizeof(struct Node));
    node->data = val;
    node->next = NULL;
    return node;
}

int* toArray(struct Node* head, int* size) 
{
    int count = 0;
    struct Node* curr = head;

    while (curr != NULL) 
    {
        count++;
        curr = curr->next;
    }

    int* arr = (int*)malloc(count * sizeof(int));
    curr = head;

    for (int i = 0; i < count; i++) 
    {
        arr[i] = curr->data;
        curr = curr->next;
    }

    *size = count;
    return arr;
}

int main() 
{
    struct Node* head1 = newNode(1);
    head1->next = newNode(2);
    head1->next->next = newNode(3);
    head1->next->next->next = newNode(4);
    head1->next->next->next->next = newNode(5);

    int size1;
    int* arr1 = toArray(head1, &size1);

    printf("Test 1: ");
    for (int i = 0; i < size1; i++)
        printf("%d ", arr1[i]);
    printf("\n");
    free(arr1);

    struct Node* head2 = newNode(42);

    int size2;
    int* arr2 = toArray(head2, &size2);

    printf("Test 2: ");
    for (int i = 0; i < size2; i++)
        printf("%d ", arr2[i]);
    printf("\n");
    free(arr2);

    struct Node* head3 = newNode(10);
    head3->next = newNode(20);

    int size3;
    int* arr3 = toArray(head3, &size3);

    printf("Test 3: ");
    for (int i = 0; i < size3; i++)
        printf("%d ", arr3[i]);
    printf("\n");
    free(arr3);

    return 0;
}