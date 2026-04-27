#include <stdio.h>
#include <stdlib.h>

// Node structure
struct Node {
    int data;
    struct Node* next;
};

// Create node
struct Node* createNode(int value) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = value;
    newNode->next = NULL;
    return newNode;
}

// Insert at end
struct Node* insertEnd(struct Node* head, int value) {
    struct Node* newNode = createNode(value);

    if (head == NULL)
        return newNode;

    struct Node* temp = head;
    while (temp->next != NULL)
        temp = temp->next;

    temp->next = newNode;
    return head;
}

// Get length
int getLength(struct Node* head) {
    int count = 0;
    while (head != NULL) {
        count++;
        head = head->next;
    }
    return count;
}

// Rotate right by k
struct Node* rotateRight(struct Node* head, int k) {
    if (head == NULL || head->next == NULL || k == 0)
        return head;

    int n = getLength(head);
    k = k % n;  // important

    if (k == 0)
        return head;

    struct Node* temp = head;

    // go to last node
    while (temp->next != NULL)
        temp = temp->next;

    // make circular
    temp->next = head;

    // move to (n-k)th node
    int steps = n - k;
    struct Node* newTail = head;

    for (int i = 1; i < steps; i++) {
        newTail = newTail->next;
    }

    struct Node* newHead = newTail->next;

    // break circle
    newTail->next = NULL;

    return newHead;
}

// Display
void display(struct Node* head) {
    while (head != NULL) {
        printf("%d ", head->data);
        head = head->next;
    }
}

int main() {
    int n, x, k;
    struct Node* head = NULL;

    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
        scanf("%d", &x);
        head = insertEnd(head, x);
    }

    scanf("%d", &k);

    head = rotateRight(head, k);

    display(head);

    return 0;
}