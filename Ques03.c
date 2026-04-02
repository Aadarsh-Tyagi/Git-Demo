// Delete a Node in Single Linked List

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

struct Node* deleteXthNode(struct Node* head, int x) 
{
    if (head == NULL)
        return NULL;

    if (x == 1) 
    {
        struct Node* temp = head;
        head = head->next;
        free(temp);
        return head;
    }

    struct Node* curr = head;
    int count = 1;

    while (curr != NULL && count < x - 1) 
    {
        curr = curr->next;
        count++;
    }

    struct Node* toDelete = curr->next;
    curr->next = toDelete->next;
    free(toDelete);

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
    head1->next->next->next = newNode(4);
    head1->next->next->next->next = newNode(5);

    printf("Before: ");
    printList(head1);
    head1 = deleteXthNode(head1, 3);
    printf("After (x=3): ");
    printList(head1);

    printf("\n");

    struct Node* head2 = newNode(10);
    head2->next = newNode(20);
    head2->next->next = newNode(30);

    printf("Before: ");
    printList(head2);
    head2 = deleteXthNode(head2, 1);
    printf("After (x=1): ");
    printList(head2);

    printf("\n");

    struct Node* head3 = newNode(5);
    head3->next = newNode(10);
    head3->next->next = newNode(15);
    head3->next->next->next = newNode(20);

    printf("Before: ");
    printList(head3);
    head3 = deleteXthNode(head3, 4);
    printf("After (x=4): ");
    printList(head3);

    printf("\n");

    struct Node* head4 = newNode(42);
    printf("Before: ");
    printList(head4);
    head4 = deleteXthNode(head4, 1);
    printf("After (x=1): ");
    if (head4 == NULL)
        printf("NULL\n");

    return 0;
}