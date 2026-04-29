#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

struct Node* insertEnd(struct Node* head, int data) {
    struct Node* newNode = createNode(data);
    if (head == NULL) return newNode;
    struct Node* temp = head;
    while (temp->next != NULL)
        temp = temp->next;
    temp->next = newNode;
    return head;
}

// Merge two sorted lists into one sorted list
struct Node* mergeSorted(struct Node* a, struct Node* b) {
    // Use a dummy head to simplify edge cases
    struct Node dummy;
    dummy.next = NULL;
    struct Node* tail = &dummy;

    while (a != NULL && b != NULL) {
        if (a->data <= b->data) {
            tail->next = a;
            a = a->next;
        } else {
            tail->next = b;
            b = b->next;
        }
        tail = tail->next;
    }

    // Attach remaining nodes
    tail->next = (a != NULL) ? a : b;

    return dummy.next;
}

void traverse(struct Node* head) {
    int first = 1;
    while (head != NULL) {
        if (!first) printf(" ");
        printf("%d", head->data);
        head = head->next;
        first = 0;
    }
    printf("\n");
}

int main() {
    int n;
    scanf("%d", &n);
    struct Node* listA = NULL;
    for (int i = 0; i < n; i++) {
        int val; scanf("%d", &val);
        listA = insertEnd(listA, val);
    }

    int m;
    scanf("%d", &m);
    struct Node* listB = NULL;
    for (int i = 0; i < m; i++) {
        int val; scanf("%d", &val);
        listB = insertEnd(listB, val);
    }

    struct Node* merged = mergeSorted(listA, listB);
    traverse(merged);
    return 0;
}