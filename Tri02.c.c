#include <stdio.h> 
#include <string.h>

int main()

{
    char zoo[100]; // for null char
    int i , z_count = 0 , o_count = 0 , zoo_count = 0;

    printf("Enter the string : ");
    scanf("%50s",zoo); // for 20 char

    
    
    

    
    
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

    for (i=0 ; i < o_count ; i++) // o count
    {
        if (zoo[i] == 'o')
        {
            o_count ++ ;
        }
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