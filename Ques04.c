// Linked List Insertion at end

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

struct Node* insertAtEnd(struct Node* head, int x) 
{
    struct Node* temp = newNode(x);

    if (head == NULL)
        return temp;

    struct Node* curr = head;
    while (curr->next != NULL)
        curr = curr->next;

    curr->next = temp;
    return head;
}

void printList(struct Node* head) 
{
    struct Node* temp = head;
    while (temp != NULL) 
    {
        printf("%d", temp->data);
        if (temp->next != NULL)
            printf(" -> ");
        temp = temp->next;
    }
    printf(" -> NULL\n");
}

int main() 
{
    struct Node* head1 = newNode(1);
    head1->next = newNode(2);
    head1->next->next = newNode(3);

    printf("Before: ");
    printList(head1);
    head1 = insertAtEnd(head1, 4);
    printf("After:  ");
    printList(head1);

    printf("\n");

    struct Node* head2 = NULL;
    printf("Before: NULL\n");
    head2 = insertAtEnd(head2, 5);
    printf("After:  ");
    printList(head2);

    printf("\n");

    struct Node* head3 = newNode(10);
    printf("Before: ");
    printList(head3);
    head3 = insertAtEnd(head3, 20);
    printf("After:  ");
    printList(head3);

    return 0;
}