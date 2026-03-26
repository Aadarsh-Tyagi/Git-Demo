#include <stdio.h>
#include <stdlib.h>
#include <time.h>

struct node {
    int data;
    struct node *next;
};

struct node* insertatbegin(struct node *head, int val) {
    struct node *newnode = (struct node*)malloc(sizeof(struct node));
    newnode->data = val;
    newnode->next = head;
    return newnode;
}

struct node* insertatend(struct node *head, int val) {
    struct node *newnode = (struct node*)malloc(sizeof(struct node));
    newnode->data = val;
    newnode->next = NULL;
    if (head == NULL) return newnode;
    struct node *temp = head;
    while (temp->next != NULL)
        temp = temp->next;
    temp->next = newnode;
    return head;
}

int main() {
    struct node *head = NULL;
    clock_t start, end;

    for (int i = 0; i < 5000; i++) {
        struct node *newnode = (struct node*)malloc(sizeof(struct node));
        newnode->data = i + 1;
        newnode->next = head;
        head = newnode;
    }

    start = clock();
    for (int r = 0; r < 1000; r++)
        head = insertatbegin(head, 99);
    end = clock();
    printf("Insert at beginning: %f sec\n", (double)(end - start) / CLOCKS_PER_SEC);

    start = clock();
    for (int r = 0; r < 1000; r++)
        head = insertatend(head, 99);
    end = clock();
    printf("Insert at end: %f sec\n", (double)(end - start) / CLOCKS_PER_SEC);

    return 0;
}