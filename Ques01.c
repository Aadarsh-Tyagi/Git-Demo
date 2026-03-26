// Reverse a singly linked list (iterative method).

#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *next;
};

struct node* createNode(int value)
{
    struct node *newNode = (struct node*)malloc(sizeof(struct node));
    newNode->data = value;
    newNode->next = NULL;
    return newNode;
}

struct node* reverseList(struct node *head)
{
    struct node *prev = NULL;
    struct node *current = head;
    struct node *next = NULL;

    while(current != NULL)
    {
        next = current->next;
        current->next = prev;
        prev = current;
        current = next;
    }

    return prev;   
}

void display(struct node *head)
{
    struct node *temp = head;

    while(temp != NULL)
    {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }

    printf("NULL\n");
}

int main()
{
    struct node *head;

    struct node *n1 = createNode(10);
    struct node *n2 = createNode(20);
    struct node *n3 = createNode(30);

    head = n1;
    n1->next = n2;
    n2->next = n3;

    printf("Original List:\n");
    display(head);

    head = reverseList(head);

    printf("Reversed List:\n");
    display(head);

    return 0;
}