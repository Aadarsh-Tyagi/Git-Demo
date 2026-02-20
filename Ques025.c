/*
Q25 (Conditional Statements)
Write a program to implement a basic calculator using switch-case for +, -, *, /, %.

Show Sample Test Cases
Input 1:
4 2 +
Output 1:
6
Input 2:
10 3 %
Output 2:
1
Input 3:
15 5 /
Output 3:
3
*/

#include <stdio.h>

int main() {
    int a, b;
    char op;
    int result;

    printf("Enter two numbers and an operator: ");
    scanf("%d %d %c", &a, &b, &op);

    switch(op) {
        case '+':
            result = a + b;
            printf("%d", result);
            break;

        case '-':
            result = a - b;
            printf("%d", result);
            break;

        case '*':
            result = a * b;
            printf("%d", result);
            break;

        case '/':
            if (b == 0)
                printf("Division by zero not allowed");
            else {
                result = a / b;
                printf("%d", result);
            }
            break;

        case '%':
            if (b == 0)
                printf("Modulo by zero not allowed");
            else {
                result = a % b;
                printf("%d", result);
            }
            break;

        default:
            printf("Invalid operator");
    }

    return 0;
}
