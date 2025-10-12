/*
Problem
You are required to enter a word that consists of  and  that denote the number of Zs and Os respectively. The input word is considered similar to word zoo if .

Determine if the entered word is similar to word zoo.

For example, words such as zzoooo and zzzoooooo are similar to word zoo but not the words such as zzooo and zzzooooo.

Input format

First line: A word that starts with several Zs and continues by several Os.
Note: The maximum length of this word must be .
Output format

Print Yes if the input word can be considered as the string zoo otherwise, print No.

Sample Input
zzzoooooo
Sample Output
Yes

Time Limit: 0.5
Memory Limit: 256
Source Limit:
*/

#include <stdio.h> 
#include <string.h>

int main()

{
    char zoo[100]; // for null char
    int i , z_count = 0 , o_count = 0 , zoo_count = 0;

    printf("Enter the word zoo(with or without variations):");
    scanf("%50s",zoo); // for 20 char

    for(i=0; zoo[i] != '\0'; i++)
    {
        zoo_count ++ ; // length calculation
    }
    printf("Length of the character: %d\n", zoo_count);

    if (zoo_count > 20)
    {
        printf("No\n"); // boundary condition
        return 0 ;
    }
    
    for (i=0 ; i < zoo_count ; i++) // z count
    {
        if (zoo[i] == 'z')
        {
            z_count ++ ;
        }
    }

    if (z_count == 0)
    {
        printf("No\n"); // boundary for z count
        return 0 ;
    }

    for (i=0 ; i < zoo_count ; i++) // o count
    {
        if (zoo[i] == 'o')
        {
            o_count ++ ;
        }
    }

    if (o_count == 0)
    {
        printf("No\n"); // boundary for o count
        return 0 ;
    }

    if  (o_count == 2 * z_count) // condition check
    {
        printf("Yes\n");

    }
    else
    {
        printf("No\n");
    }
    
    return 0;
}