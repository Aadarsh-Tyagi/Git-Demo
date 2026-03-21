// Delete the first node.

#include <stdio.h>
#include <stdlib.h>

struct node 
{
    int data;
    struct node *next;
};

struct node* deletefirst(struct node *head) 
{
    if (head == NULL) return NULL;
    struct node *temp = head;
    head = head->next;
    free(temp);
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

    head = deletefirst(head);

    temp = head;
    while (temp != NULL) 
    {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");

    return 0;
}