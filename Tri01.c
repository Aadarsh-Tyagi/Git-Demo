#include <stdio.h>

int main()
{
    int age = 30;
    float sal = 1500.50;

    printf("\nValue of age = %d", age);
    printf("\nAddress of age = %p", (void *)&age);

    printf("\nValue of sal = %f", sal);
    printf("\nAddress of sal = %p", (void *)&sal);

    return 0;
}
