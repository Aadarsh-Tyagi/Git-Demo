// All operations 

#include <stdio.h>
#define MAX 100

int queue[MAX];
int front = -1, rear = -1;

// Enqueue
void enqueue(int x) 
{
    if (rear == MAX - 1) 
    {
        printf("Queue Overflow\n");
        return;
    }
    if (front == -1)
        front = 0;
    queue[++rear] = x;
    printf("%d inserted\n", x);
}

// Dequeue
void dequeue() 
{
    if (front == -1 || front > rear) 
    {
        printf("Queue Underflow\n");
        return;
    }
    printf("%d deleted\n", queue[front++]);
}

// Peek (Front)
void peek() 
{
    if (front == -1 || front > rear) 
    {
        printf("Queue is empty\n");
        return;
    }
    printf("Front element: %d\n", queue[front]);
}

// Rear element
void getRear() 
{
    if (rear == -1 || front > rear) 
    {
        printf("Queue is empty\n");
        return;
    }
    printf("Rear element: %d\n", queue[rear]);
}

// Check empty
void isEmpty() 
{
    if (front == -1 || front > rear)
        printf("Queue is empty\n");
    else
        printf("Queue is not empty\n");
}

// Check full
void isFull() 
{
    if (rear == MAX - 1)
        printf("Queue is full\n");
    else
        printf("Queue is not full\n");
}

// Display queue
void display() 
{
    if (front == -1 || front > rear) 
    {
        printf("Queue is empty\n");
        return;
    }
    printf("Queue elements: ");
    for (int i = front; i <= rear; i++) 
    {
        printf("%d ", queue[i]);
    }
    printf("\n");
}

// Main function (Menu-driven)
int main() 
{
    int choice, value;

    while (1) 
    {
        printf("\n--- QUEUE MENU ---\n");
        printf("1. Enqueue\n");
        printf("2. Dequeue\n");
        printf("3. Peek (Front)\n");
        printf("4. Rear\n");
        printf("5. isEmpty\n");
        printf("6. isFull\n");
        printf("7. Display\n");
        printf("8. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) 
        {
            case 1:
                printf("Enter value: ");
                scanf("%d", &value);
                enqueue(value);
                break;
            case 2:
                dequeue();
                break;
            case 3:
                peek();
                break;
            case 4:
                getRear();
                break;
            case 5:
                isEmpty();
                break;
            case 6:
                isFull();
                break;
            case 7:
                display();
                break;
            case 8:
                printf("Exiting...\n");
                return 0;
            default:
                printf("Invalid choice\n");
        }
    }
}