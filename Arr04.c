/*
Enter 'n' Nos. and Print their Sum
*/
#include <stdio.h>

int main()

{
    int count = 0;
    int arr [100];
    int a ;

    printf("Enter the Value you want :\n");
    scanf("%d",&a);
  
    for (int i=0;i<=a-1;i++)
    {
        count=count+arr[i];
        printf ("Enter Element %d",arr[i]);
    }
    return 0;
    
}