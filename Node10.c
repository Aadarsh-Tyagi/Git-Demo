// Delete a node with a given value.

#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *next;
};

struct node* createNode(int value)
{
    struct node *newNode;
    newNode = (struct node*)malloc(sizeof(struct node));

    newNode->data = value;
    newNode->next = NULL;

    return newNode;
}

struct node* deleteNode(struct node *head, int value)
{
    struct node *temp = head;
    struct node *prev = NULL;

    if (temp != NULL && temp->data == value)
    {
        head = temp->next;
        free(temp);
        return head;
    }

    while (temp != NULL && temp->data != value)
    {
        prev = temp;
        temp = temp->next;
    }

    if (temp == NULL)
    {
        printf("Value not found\n");
        return head;
    }

    prev->next = temp->next;
    free(temp);

    return head;
}

void display(struct node *head)
{
    struct node *temp = head;

    while (temp != NULL)
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

    head = deleteNode(head, 20);

    printf("After Deletion:\n");
    display(head);

    return 0;
}