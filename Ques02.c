// Implement queue using two stacks

#include <stdio.h>
#define MAX 100

int stack1[MAX], stack2[MAX];
int top1 = -1, top2 = -1;

// Push into stack1
void enqueue(int x) {
    if (top1 == MAX - 1) {
        printf("Queue Overflow\n");
        return;
    }
    stack1[++top1] = x;
}

// Pop from stack2
int dequeue() {
    if (top2 == -1) {
        if (top1 == -1) {
            printf("Queue Underflow\n");
            return -1;
        }
        // Transfer elements
        while (top1 != -1) {
            stack2[++top2] = stack1[top1--];
        }
    }
    return stack2[top2--];
}

// Display queue
void display() {
    if (top1 == -1 && top2 == -1) {
        printf("Queue is empty\n");
        return;
    }

    // Elements in stack2 (front part)
    for (int i = top2; i >= 0; i--)
        printf("%d ", stack2[i]);

    // Elements in stack1 (rear part)
    for (int i = 0; i <= top1; i++)
        printf("%d ", stack1[i]);

    printf("\n");
}

int main() {
    enqueue(10);
    enqueue(20);
    enqueue(30);

    printf("Dequeued: %d\n", dequeue());
    display();

    enqueue(40);
    display();

    return 0;
}