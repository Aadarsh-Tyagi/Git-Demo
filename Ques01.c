// Remove all occurrences of duplicates in a sorted linked list

#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *next;
};

struct Node *newNode(int val)
{
    struct Node *node = (struct Node *)malloc(sizeof(struct Node));
    node->data = val;
    node->next = NULL;
    return node;
}

struct Node *removeAllDuplicates(struct Node *head)
{
    struct Node *dummy = newNode(0);
    dummy->next = head;

    struct Node *prev = dummy;
    struct Node *curr = head;

    while (curr != NULL)
    {

        if (curr->next != NULL && curr->data == curr->next->data)
        {

            while (curr->next != NULL && curr->data == curr->next->data)
            {
                struct Node *temp = curr->next;
                curr->next = temp->next;
                free(temp);
            }

            struct Node *temp = curr;
            prev->next = curr->next;
            curr = curr->next;
            free(temp);
        }
        else
        {
            prev = curr;
            curr = curr->next;
        }
    }

    struct Node *newHead = dummy->next;
    free(dummy);
    return newHead;
}

void printList(struct Node *head)
{
    struct Node *temp = head;
    if (temp == NULL)
    {
        printf("NULL\n");
        return;
    }
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
    struct Node *head1 = newNode(1);
    head1->next = newNode(2);
    head1->next->next = newNode(2);
    head1->next->next->next = newNode(3);
    head1->next->next->next->next = newNode(3);
    head1->next->next->next->next->next = newNode(4);

    printf("Before: ");
    printList(head1);
    head1 = removeAllDuplicates(head1);
    printf("After:  ");
    printList(head1);

    printf("\n");

    struct Node *head2 = newNode(1);
    head2->next = newNode(1);
    head2->next->next = newNode(1);
    head2->next->next->next = newNode(2);
    head2->next->next->next->next = newNode(3);

    printf("Before: ");
    printList(head2);
    head2 = removeAllDuplicates(head2);
    printf("After:  ");
    printList(head2);

    printf("\n");

    struct Node *head3 = newNode(1);
    head3->next = newNode(1);
    head3->next->next = newNode(2);
    head3->next->next->next = newNode(2);

    printf("Before: ");
    printList(head3);
    head3 = removeAllDuplicates(head3);
    printf("After:  ");
    printList(head3);

    printf("\n");

    struct Node *head4 = newNode(1);
    head4->next = newNode(2);
    head4->next->next = newNode(3);

    printf("Before: ");
    printList(head4);
    head4 = removeAllDuplicates(head4);
    printf("After:  ");
    printList(head4);

    printf("\n");

    struct Node *head5 = newNode(1);
    head5->next = newNode(2);
    head5->next->next = newNode(3);
    head5->next->next->next = newNode(3);

    printf("Before: ");
    printList(head5);
    head5 = removeAllDuplicates(head5);
    printf("After:  ");
    printList(head5);

    return 0;
}