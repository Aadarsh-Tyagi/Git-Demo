// Remove loop in Linked List

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

int removeCycle(struct Node* head) 
{
    if (head == NULL || head->next == NULL)
        return 0;

    struct Node* slow = head;
    struct Node* fast = head;

    int cycleFound = 0;
    while (fast != NULL && fast->next != NULL) 
    {
        slow = slow->next;
        fast = fast->next->next;
        if (slow == fast) 
        {
            cycleFound = 1;
            break;
        }
    }

    if (!cycleFound)
        return 0; 

    slow = head;

    if (slow == fast) 
    {
        while (fast->next != slow)
            fast = fast->next;
    } 
    else 
    {
        while (slow->next != fast->next) 
        {
            slow = slow->next;
            fast = fast->next;
        }
    }

    fast->next = NULL;
    return 1; 
}

int main() 
{
    struct Node* head1 = newNode(1);
    head1->next = newNode(2);
    head1->next->next = newNode(3);
    head1->next->next->next = newNode(4);
    head1->next->next->next->next = newNode(5);
    head1->next->next->next->next->next = head1->next; 

    printf("Test 1 (cycle at pos 1): %s\n", removeCycle(head1) ? "true" : "false");

    struct Node* head2 = newNode(3);
    head2->next = newNode(4);
    head2->next->next = newNode(5);
    head2->next->next->next = head2; 

    printf("Test 2 (cycle at pos 0): %s\n", removeCycle(head2) ? "true" : "false");

    struct Node* head3 = newNode(1);
    head3->next = newNode(2);
    head3->next->next = newNode(3);

    printf("Test 3 (no cycle):       %s\n", removeCycle(head3) ? "true" : "false");

    struct Node* head4 = newNode(1);
    printf("Test 4 (single node):    %s\n", removeCycle(head4) ? "true" : "false");

    struct Node* head5 = newNode(1);
    head5->next = head5; 

    printf("Test 5 (self loop):      %s\n", removeCycle(head5) ? "true" : "false");

    return 0;
}