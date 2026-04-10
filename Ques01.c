// Implement two stack in a single array

#include <stdio.h>
#define MAX 10

int arr[MAX];
int top1 = -1;
int top2 = MAX;

// Push into Stack1
void push1(int x) 
{
    if (top1 + 1 == top2) 
    {
        printf("Stack Overflow\n");
        return;
    }
    arr[++top1] = x;
}

// Push into Stack2
void push2(int x) 
{
    if (top1 + 1 == top2) 
    {
        printf("Stack Overflow\n");
        return;
    }
    arr[--top2] = x;
}

// Pop from Stack1
int pop1() 
{
    if (top1 == -1) 
    {
        printf("Stack1 Underflow\n");
        return -1;
    }
    return arr[top1--];
}

// Pop from Stack2
int pop2() 
{
    if (top2 == MAX) 
    {
        printf("Stack2 Underflow\n");
        return -1;
    }
    return arr[top2++];
}

// Display both stacks
void display() 
{
    printf("Stack1: ");
    for (int i = 0; i <= top1; i++)
        printf("%d ", arr[i]);

    printf("\nStack2: ");
    for (int i = MAX - 1; i >= top2; i--)
        printf("%d ", arr[i]);

    printf("\n");
}

int main() 
{
    push1(10);
    push1(20);
    push2(100);
    push2(200);

    display();

    printf("Pop Stack1: %d\n", pop1());
    printf("Pop Stack2: %d\n", pop2());

    display();

    return 0;
}