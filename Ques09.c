// Reverse a Doubly Linked List

#include <stdio.h>
#include <stdlib.h>

struct Node 
{
    int data;
    struct Node* next;
    struct Node* prev;
};

struct Node* newNode(int val) 
{
    struct Node* node = (struct Node*)malloc(sizeof(struct Node));
    node->data = val;
    node->next = NULL;
    node->prev = NULL;
    return node;
}

struct Node* reverseDLL(struct Node* head) 
{
    if (head == NULL || head->next == NULL)
        return head;

    struct Node* curr = head;
    struct Node* temp = NULL;

    while (curr != NULL) 
    {
        temp = curr->prev;
        curr->prev = curr->next;
        curr->next = temp;
        curr = curr->prev;
    }

    return temp->prev;
}

void printList(struct Node* head) 
{
    struct Node* temp = head;
    while (temp != NULL) 
    {
        printf("%d", temp->data);
        if (temp->next != NULL)
            printf(" <-> ");
        temp = temp->next;
    }
    printf(" <-> NULL\n");
}

int main() 
{
    struct Node* head1 = newNode(1);
    head1->next = newNode(2);
    head1->next->prev = head1;
    head1->next->next = newNode(3);
    head1->next->next->prev = head1->next;
    head1->next->next->next = newNode(4);
    head1->next->next->next->prev = head1->next->next;
    head1->next->next->next->next = newNode(5);
    head1->next->next->next->next->prev = head1->next->next->next;

    printf("Before: ");
    printList(head1);
    head1 = reverseDLL(head1);
    printf("After:  ");
    printList(head1);

    printf("\n");

    struct Node* head2 = newNode(1);
    head2->next = newNode(2);
    head2->next->prev = head2;

    printf("Before: ");
    printList(head2);
    head2 = reverseDLL(head2);
    printf("After:  ");
    printList(head2);

    printf("\n");

    struct Node* head3 = newNode(10);

    printf("Before: ");
    printList(head3);
    head3 = reverseDLL(head3);
    printf("After:  ");
    printList(head3);

    return 0;
}