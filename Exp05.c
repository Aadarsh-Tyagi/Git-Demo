//
//  Exp05.c
//  Coding
//
//  Created by Arsh on 27/08/25.
//

#include <stdio.h>

int main (void)
{
    float celsius, fahrenheit;
    printf("Enter temperature in Celsius: ");
    scanf("%f", &celsius);
    fahrenheit = (celsius * 9.0 / 5.0) + 32;
    printf("%.2f Celsius is equal to %.2f Fahrenheit.\n", celsius, fahrenheit);

    return 0;
}
