/*
Menu based system to check whether a number is prime , palindrome or armstrong according to the user 
*/

#include <stdio.h>

// Function declarations
void check_Prime(int n);
void check_Palindrome(int n);
void check_Armstrong(int n);

int main()
{
    int num, code;
    char try_Again;

    do 
    {
        printf("Enter the Desired Number: ");
        scanf("%d", &num);

        printf("Pick what to check:\n");
        printf("\t111 :- Prime Number\n\t222 :- Palindrome Number\n\t333 :- Armstrong Number\n");
        printf("Enter the Code: ");
        scanf("%d", &code);

        switch (code) 
        {
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

void check_Prime(int n)
{
    int i, is_Prime = 1;
    if (n < 2) 
    {
        printf("%d is not a prime number.", n);
        return;
    }
    for (i = 2; i <= n / 2; i++) 
    {
        if (n % i == 0) 
        {
            is_Prime = 0;
            break;
        }
    }
    if (is_Prime)
        printf("%d is a prime number.", n);
    else
        printf("%d is not a prime number.", n);
}

void check_Palindrome(int n)
{
    int rev = 0, orig = n;
    while (n != 0) 
    {
        rev = rev * 10 + n % 10;
        n = n / 10;
    }
    if (orig == rev)
        printf("%d is a palindrome number.", orig);
    else
        printf("%d is not a palindrome number.", orig);
}

void check_Armstrong(int n)
{
    int sum = 0, orig = n, rem;
    while (n != 0) 
    {
        rem = n % 10;
        sum += rem * rem * rem;
        n = n / 10;
    }
    if (sum == orig)
        printf("%d is an Armstrong number.", orig);
    else
        printf("%d is not an Armstrong number.", orig);
}
