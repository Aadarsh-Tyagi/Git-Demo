#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

// Node structure for stack
struct Node {
    int data;
    struct Node* next;
};

// Push
void push(struct Node** top, int value) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = value;
    newNode->next = *top;
    *top = newNode;
}

// Pop
int pop(struct Node** top) {
    if (*top == NULL) {
        return 0; // simple handling
    }
    struct Node* temp = *top;
    int value = temp->data;
    *top = temp->next;
    free(temp);
    return value;
}

// Evaluate postfix
int evaluate(char* exp) {
    struct Node* top = NULL;
    int i = 0;

    while (exp[i] != '\0') {

        // Skip spaces
        if (exp[i] == ' ') {
            i++;
            continue;
        }

        // If digit → push
        if (isdigit(exp[i])) {
            push(&top, exp[i] - '0');
        }
        // Operator
        else {
            int b = pop(&top);
            int a = pop(&top);
            int result;

            switch (exp[i]) {
                case '+': result = a + b; break;
                case '-': result = a - b; break;
                case '*': result = a * b; break;
                case '/': result = a / b; break;
            }

            push(&top, result);
        }

        i++;
    }

    return pop(&top);
}

int main() {
    char exp[100];

    // Read full line including spaces
    fgets(exp, sizeof(exp), stdin);

    int result = evaluate(exp);

    printf("%d", result);

    return 0;
}