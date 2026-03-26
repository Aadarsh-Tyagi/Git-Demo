#include <stdio.h>
#include <stdlib.h>
#include <time.h>

struct node {
    int data;
    struct node *next;
};

void traversal(struct node *head) {
    struct node *temp = head;
    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

int main() {
    struct node *head = NULL;
    struct node *temp;
    clock_t start, end;

    for (int i = 0; i < 5000; i++) {
        struct node *newnode = (struct node*)malloc(sizeof(struct node));
        newnode->data = i + 1;
        newnode->next = NULL;
        if (head == NULL) {
            head = newnode;
            temp = head;
        } else {
            temp->next = newnode;
            temp = temp->next;
        }
    }

    start = clock();
    traversal(head);
    end = clock();

    printf("Time: %f sec\n", (double)(end - start) / CLOCKS_PER_SEC);
    return 0;
}