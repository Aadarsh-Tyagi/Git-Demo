#include <stdio.h>
#include <stdlib.h>
#include <time.h>

struct node {
    int data;
    struct node *next;
};

struct node* deleteatbegin(struct node *head) {
    if (head == NULL) return NULL;
    struct node *temp = head;
    head = head->next;
    free(temp);
    return head;
}

struct node* deleteatend(struct node *head) {
    if (head == NULL) return NULL;
    if (head->next == NULL) { free(head); return NULL; }
    struct node *temp = head;
    while (temp->next->next != NULL)
        temp = temp->next;
    free(temp->next);
    temp->next = NULL;
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
        head = deleteatbegin(head);
    end = clock();
    printf("Delete at beginning: %f sec\n", (double)(end - start) / CLOCKS_PER_SEC);

    for (int i = 0; i < 5000; i++) {
        struct node *newnode = (struct node*)malloc(sizeof(struct node));
        newnode->data = i + 1;
        newnode->next = head;
        head = newnode;
    }

    start = clock();
    for (int r = 0; r < 1000; r++)
        head = deleteatend(head);
    end = clock();
    printf("Delete at end: %f sec\n", (double)(end - start) / CLOCKS_PER_SEC);

    return 0;
}