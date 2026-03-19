// Search an element in a linked list.

#include <stdio.h>
#include <stdlib.h>

struct node 
{
    int data;
    struct node *next;
};

void search(struct node *head, int key) 
{
    if (head == NULL) 
    {
        printf("List is empty\n");
        return;
    }
    struct node *temp = head;
    int pos = 1;
    while (temp != NULL) 
    {
        if (temp->data == key) 
        {
            printf("Found %d at position %d\n", key, pos);
            return;
        }
        temp = temp->next;
        pos++;
    }
    printf("%d not found in list\n", key);
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
        struct node *newnode = (struct node*)malloc(sizeof(struct node));
        newnode->data = val;
        newnode->next = NULL;
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

    printf("Enter element to search: ");
    scanf("%d", &val);
    search(head, val);

    return 0;
}