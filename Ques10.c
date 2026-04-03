// Linked List Length Even or Odd

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

int isLengthEven(struct Node* head) 
{
    struct Node* curr = head;

    while (curr != NULL && curr->next != NULL)
        curr = curr->next->next;

    if (curr == NULL)
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

    printList(head1);
    printf("Length is: %s\n", isLengthEven(head1) ? "Even" : "Odd");

    printf("\n");

    struct Node* head2 = newNode(1);
    head2->next = newNode(2);
    head2->next->next = newNode(3);
    head2->next->next->next = newNode(4);
    head2->next->next->next->next = newNode(5);

    printList(head2);
    printf("Length is: %s\n", isLengthEven(head2) ? "Even" : "Odd");

    printf("\n");

    struct Node* head3 = newNode(1);

    printList(head3);
    printf("Length is: %s\n", isLengthEven(head3) ? "Even" : "Odd");

    printf("\n");

    struct Node* head4 = newNode(1);
    head4->next = newNode(2);

    printList(head4);
    printf("Length is: %s\n", isLengthEven(head4) ? "Even" : "Odd");

    return 0;
}