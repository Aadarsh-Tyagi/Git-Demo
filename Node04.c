// Write a program to create a singly linked list and display all nodes of a linked list.

#include <stdio.h>
#include <stdlib.h>

struct node 
{
    int data;
    struct node *next;
};

struct node* createnode(int val) 
{
    struct node *newnode = (struct node*)malloc(sizeof(struct node));
    newnode->data = val;
    newnode->next = NULL;
    return newnode;
}

int main() 
{
    int n, val;
    struct node *head = NULL, *temp = NULL;

    printf("Enter number of nodes: ");
    scanf("%d", &n);

    for (int i = 0; i < n; i++) 
    {
        scanf("%d", &val);
        struct node *newnode = createnode(val);
        if (head == NULL) 
        {
            head = newnode;
            temp = head;
        } 
        else 
        {
            temp->next = newnode;
            temp = temp->next;
        }
    }

    temp = head;
    while (temp != NULL) 
    {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");

    return 0;
}