// Check If Circular Linked List

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

int isCircular(struct Node* head) 
{
    if (head == NULL)
        return 0;

    struct Node* curr = head->next;

    while (curr != NULL && curr != head)
        curr = curr->next;

    if (curr == head)
        return 1;

    return 0;
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
    head1->next->next->next = newNode(4);
    head1->next->next->next->next = head1;

    printf("Test 1 (circular):     %s\n", isCircular(head1) ? "true" : "false");

    struct Node* head2 = newNode(1);
    head2->next = newNode(2);
    head2->next->next = newNode(3);

    printf("Test 2 (not circular): %s\n", isCircular(head2) ? "true" : "false");

    struct Node* head3 = newNode(1);
    head3->next = head3;

    printf("Test 3 (self loop):    %s\n", isCircular(head3) ? "true" : "false");

    struct Node* head4 = newNode(1);

    printf("Test 4 (single node):  %s\n", isCircular(head4) ? "true" : "false");

    struct Node* head5 = newNode(1);
    head5->next = newNode(2);
    head5->next->next = head5;

    printf("Test 5 (two nodes):    %s\n", isCircular(head5) ? "true" : "false");

    return 0;
}