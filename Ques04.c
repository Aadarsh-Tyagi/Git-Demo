// Detect whether a loop exists in a linked list.

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

int detectLoop(struct node *head)
{
    struct node *slow = head;
    struct node *fast = head;

    while(fast != NULL && fast->next != NULL)
    {
        slow = slow->next;
        fast = fast->next->next;

        if(slow == fast)
            return 1;   
    }

    return 0;
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
    struct node *n4 = createNode(40);

    head = n1;
    n1->next = n2;
    n2->next = n3;
    n3->next = n4;

    n4->next = n2;

    if(detectLoop(head))
        printf("Loop detected in linked list\n");
    else
        printf("No loop found\n");

    return 0;
}