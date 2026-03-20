// Insert a node at the end of the list.

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

struct node* insertatend(struct node *head, int val) 
{
    struct node *newnode = createnode(val);
    if (head == NULL) return newnode;
    struct node *temp = head;
    while (temp->next != NULL)
        temp = temp->next;
    temp->next = newnode;
    return head;
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

    printf("Enter value to insert at end: ");
    scanf("%d", &val);
    head = insertatend(head, val);

    temp = head;
    while (temp != NULL) 
    {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");

    return 0;
}