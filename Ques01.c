#include <stdio.h>
#include <string.h>

void reverse(char str[], int left, int right) {
    // Base case: pointers meet or cross
    if (left >= right) return;

    // Swap characters at both ends
    char temp = str[left];
    str[left] = str[right];
    str[right] = temp;

    // Recurse inward
    reverse(str, left + 1, right - 1);
}

int main() {
    char str[1000];
    scanf("%s", str);

    reverse(str, 0, strlen(str) - 1);

    printf("%s\n", str);
    return 0;
}