#include <stdio.h>

// Function declarations
void check_Prime(int n);
void check_Palindrome(int n);
void check_Armstrong(int n);

int main()
{
    int num, code;
    char try_Again;

    do {
        printf("Enter the Desired Number: ");
        scanf("%d", &num);

        printf("Pick what to check:\n");
        printf("\t111 :- Prime Number\n\t222 :- Palindrome Number\n\t333 :- Armstrong Number\n");
        printf("Enter the Code: ");
        scanf("%d", &code);

        switch (code) {
            case 111:
                check_Prime(num);
                break;
            case 222:
                check_Palindrome(num);
                break;
            case 333:
                check_Armstrong(num);
                break;
            default:
                printf("Invalid Code!\n");
        }

        printf("\nDo you want to check another number? (y/n): ");
        scanf(" %c", &try_Again);  // space before %c to consume previous newline

    } while(try_Again == 'y' || try_Again == 'Y');

    return 0;
}