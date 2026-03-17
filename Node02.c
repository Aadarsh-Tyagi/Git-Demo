// Node creation with functions and deletion at any given point

#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *next;
};

struct node *create_node(int data)
{
    struct node *new_node = (struct node *)malloc(sizeof(struct node));

    if (new_node == NULL)
    {
        printf("Memory allocation failed\n");
        exit(1);
    }

    new_node->data = data;
    new_node->next = NULL;

    return new_node;
}

void display(struct node *head)
{
    struct node *temp = head;

    printf("\nLinked List: ");

    while (temp != NULL)
    {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }

    printf("NULL\n");
}

struct node *delete_at_position(struct node *head, int pos)
{
    if (head == NULL)
    {
        printf("List is empty\n");
        return head;
    }

    struct node *temp = head;

    // Delete first node
    if (pos == 1)
    {
        head = head->next;
        free(temp);
        return head;
    }

    struct node *prev = NULL;
    int i;

    for (i = 1; i < pos && temp != NULL; i++)
    {
        prev = temp;
        temp = temp->next;
    }

    if (temp == NULL)
    {
        printf("Invalid Position\n");
        return head;
    }

    prev->next = temp->next;
    free(temp);

    return head;
}

int main()
{
    int n, i;

    printf("Enter the Number of Nodes Desired: ");
    scanf("%d", &n);

    struct node *head = NULL;
    struct node *temp = NULL;

    for (i = 0; i < n; i++)
    {
        struct node *new_node = create_node(i + 1);

        if (head == NULL)
        {
            head = new_node;
            temp = head;
        }
        else
        {
            temp->next = new_node;
            temp = new_node;
        }
    }

    display(head);

    int pos;
    printf("\nEnter position to delete: ");
    scanf("%d", &pos);

    head = delete_at_position(head, pos);

    display(head);

    return 0;
}

