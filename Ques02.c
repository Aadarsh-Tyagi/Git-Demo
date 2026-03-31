// Detect Loop in linked list

#include <stdio.h>
#include <stdlib.h>

struct Node 
{
    int data;
    struct Node* next;
};

struct Node* newNode(int val) 
{
    struct Node* node = (struct Node*)malloc(sizeof(struct Node));
    node->data = val;
    node->next = NULL;
    return node;
}

int detectLoop(struct Node* head) 
{
    if (head == NULL || head->next == NULL)
        return 0;

    struct Node* slow = head;
    struct Node* fast = head;

    while (fast != NULL && fast->next != NULL) 
    {
        slow = slow->next;
        fast = fast->next->next;

        if (slow == fast)
            return 1;
    }

    return 0; 
}

int main() 
{
    struct Node* head1 = newNode(1);
    head1->next = newNode(2);
    head1->next->next = newNode(3);
    head1->next->next->next = newNode(4);
    head1->next->next->next->next = newNode(5);
    head1->next->next->next->next->next = head1->next; 

    printf("Test 1 (loop at pos 2):  %s\n", detectLoop(head1) ? "true" : "false");

    struct Node* head2 = newNode(3);
    head2->next = newNode(4);
    head2->next->next = newNode(5);
    head2->next->next->next = head2; 

    printf("Test 2 (loop at pos 1):  %s\n", detectLoop(head2) ? "true" : "false");

    struct Node* head3 = newNode(1);
    head3->next = newNode(2);
    head3->next->next = newNode(3);

    printf("Test 3 (no loop):        %s\n", detectLoop(head3) ? "true" : "false");

    struct Node* head4 = newNode(1);
    printf("Test 4 (single node):    %s\n", detectLoop(head4) ? "true" : "false");

    struct Node* head5 = newNode(1);
    head5->next = head5;
    printf("Test 5 (self loop):      %s\n", detectLoop(head5) ? "true" : "false");

    struct Node* head6 = newNode(1);
    head6->next = newNode(2);
    head6->next->next = head6;
    printf("Test 6 (two node loop):  %s\n", detectLoop(head6) ? "true" : "false");

    return 0;
}