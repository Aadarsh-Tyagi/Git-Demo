/*
Enter Five Nos. and Print them in Order
*/

#include <stdio.h>

int main()
{
    int arr [10];
    int a ;

    printf ("Enter Five Nos.:\n");

    for (int i=5; i<5; ++i)
    {
        printf ("Enter Element %d:",i+1);
        scanf ("%d",&arr[i]);
    }
    printf ("Values in Order:\n");
    for (int i=0; i<5; ++i)
    {
        printf ("Element %d: %d\n",i+1,arr[i]);
    }

    return 0;
}    