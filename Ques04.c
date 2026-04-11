// Implement queue using two stacks with additional features

#include <stdio.h>
#define MAX 100

int stack1[MAX], stack2[MAX];
int top1 = -1, top2 = -1;

// Check if queue is empty
int isEmpty() {
    return (top1 == -1 && top2 == -1);
}

// Check if queue is full
int isFull() {
    return (top1 == MAX - 1);
}

// Enqueue
void enqueue(int x) {
    if (isFull()) {
        printf("Queue Overflow\n");
        return;
    }
    stack1[++top1] = x;
}

// Dequeue
int dequeue() {
    if (isEmpty()) {
        printf("Queue Underflow\n");
        return -1;
    }

    if (top2 == -1) {
        while (top1 != -1) {
            stack2[++top2] = stack1[top1--];
        }
    }
    return stack2[top2--];
}

// Peek (Front element)
int peek() {
    if (isEmpty()) {
        printf("Queue is empty\n");
        return -1;
    }

    if (top2 == -1) {
        while (top1 != -1) {
            stack2[++top2] = stack1[top1--];
        }
    }
    return stack2[top2];
}

// Display queue
void display() {
    if (isEmpty()) {
        printf("Queue is empty\n");
        return;
    }

    // stack2 = front part
    for (int i = top2; i >= 0; i--)
        printf("%d ", stack2[i]);

    // stack1 = rear part
    for (int i = 0; i <= top1; i++)
        printf("%d ", stack1[i]);

    printf("\n");
}

int main() {
    enqueue(10);
    enqueue(20);
    enqueue(30);

    display();

    printf("Peek: %d\n", peek());

    printf("Dequeued: %d\n", dequeue());
    display();

    enqueue(40);
    display();

    return 0;
}