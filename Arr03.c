/*
Enter 'n' Nos. and Print them in Order
*/

#include <stdio.h>

int main()

{
    int arr [100];
    int a ;

    printf("Enter the Value you want :\n");
    scanf("%d",&a);

    printf ("Enter %d Nos.:\n",a);

    for (int i=0; i<a;++i)
    {
        printf ("Enter Element %d:",i+1);
        scanf ("%d",&arr[i]);
    }
     return 0;

}