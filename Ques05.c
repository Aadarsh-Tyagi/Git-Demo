// Count nodes of linked list

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

int getLength(struct Node* head) 
{
    int count = 0;
    struct Node* curr = head;

    while (curr != NULL) 
    {
        count++;
        curr = curr->next;
    }

    return count;
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

    printList(head1);
    printf("Length: %d\n", getLength(head1));

    printf("\n");

    struct Node* head2 = newNode(10);
    printList(head2);
    printf("Length: %d\n", getLength(head2));

    printf("\n");

    struct Node* head3 = newNode(5);
    head3->next = newNode(10);
    head3->next->next = newNode(15);

    printList(head3);
    printf("Length: %d\n", getLength(head3));

    return 0;
}