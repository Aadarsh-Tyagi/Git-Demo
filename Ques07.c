// Find length of Loop

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

int countLoopNodes(struct Node* head) 
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
        {
            int count = 1;
            struct Node* curr = slow->next;

            while (curr != slow) 
            {
                count++;
                curr = curr->next;
            }

            return count;
        }
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

    printf("Test 1 (loop at pos 2): %d\n", countLoopNodes(head1));

    struct Node* head2 = newNode(1);
    head2->next = newNode(2);
    head2->next->next = newNode(3);
    head2->next->next->next = head2;

    printf("Test 2 (loop at pos 1): %d\n", countLoopNodes(head2));

    struct Node* head3 = newNode(1);
    head3->next = newNode(2);
    head3->next->next = newNode(3);

    printf("Test 3 (no loop):       %d\n", countLoopNodes(head3));

    struct Node* head4 = newNode(1);
    head4->next = head4;

    printf("Test 4 (self loop):     %d\n", countLoopNodes(head4));

    struct Node* head5 = newNode(1);
    head5->next = newNode(2);
    head5->next->next = newNode(3);
    head5->next->next->next = newNode(4);
    head5->next->next->next->next = newNode(5);
    head5->next->next->next->next->next = head5->next->next;

    printf("Test 5 (loop of 3):     %d\n", countLoopNodes(head5));

    return 0;
}