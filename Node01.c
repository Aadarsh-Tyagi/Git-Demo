// Node creation with functions and insertion at any given point

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

struct node *insert_at_position(struct node *head, int data, int pos)
{
    struct node *new_node = create_node(data);

    if (pos == 1)   // Insert at beginning
    {
        new_node->next = head;
        return new_node;
    }

    struct node *temp = head;
    int i;

    for (i = 1; i < pos - 1 && temp != NULL; i++)
    {
        temp = temp->next;
    }

    if (temp == NULL)
    {
        printf("Invalid Position\n");
        return head;
    }

    new_node->next = temp->next;
    temp->next = new_node;

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

    int data, pos;
    printf("\nEnter value to insert: ");
    scanf("%d", &data);
    printf("Enter position to insert at: ");
    scanf("%d", &pos);

    head = insert_at_position(head, data, pos);

    display(head);

    return 0;
}
