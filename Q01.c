/*
Print a pattern of numbers from 1 to n as shown below. Each of the numbers is separated
by a single space.

1 2 3 4 5 4 3 2 1
1 2 3 4   4 3 2 1
1 2 3       3 2 1
1 2           2 1
1               1
*/

#include <stdio.h>

int main()
{
    int num;
    printf("Enter number(Your choice): ");
    scanf("%d", &num);

    for (int i = num; i >= 1; i--) 
    {
        
        for (int j = 1; j <= i; j++) 
        {
            printf("%d ", j); // Left Triangle
        }

        int spaces = 2 * (num - i) - 1;
        for (int k = 0; k < spaces; k++) 
        {
            printf("  "); // two spaces for each "slot"
        }

        if (i == num) 
        {
            // First row print from n-1 down to 1
            for (int j = num - 1; j >= 1; j--) 
            {
                printf("%d ", j);
            }                                           // Right side
        } else 
        {
            // Other rows print from i down to 1
            for (int j = i; j >= 1; j--) 
            {
                printf("%d ", j);
            }
        }

        printf("\n");
    }

    return 0;
}

