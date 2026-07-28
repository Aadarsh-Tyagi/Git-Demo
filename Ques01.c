#include <stdio.h>
#include <stdlib.h>

// Node structure
struct Node {
    int data;
    struct Node* next;
};

// Create a new node
struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

// Insert at end of list
struct Node* insertEnd(struct Node* head, int data) {
    struct Node* newNode = createNode(data);
    if (head == NULL) return newNode;

    struct Node* temp = head;
    while (temp->next != NULL)
        temp = temp->next;
    temp->next = newNode;
    return head;
}

// Traverse and print
void traverse(struct Node* head) {
    struct Node* temp = head;
    int first = 1;
    while (temp != NULL) {
        if (!first) printf(" ");
        printf("%d", temp->data);
        temp = temp->next;
        first = 0;
    }
    printf("\n");
}

int main() {
    int n;
    scanf("%d", &n);

    struct Node* head = NULL;
    for (int i = 0; i < n; i++) {
        int val;
        scanf("%d", &val);
        head = insertEnd(head, val);
    }

    traverse(head);
    return 0;
}