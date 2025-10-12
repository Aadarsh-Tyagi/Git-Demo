/* https://www.hackerearth.com/practice/basic-programming/input-output/basics-of-
input-output/practice-problems/algorithm/is-zoo-f6f309e7/
*/
#include <stdio.h>
#include <string.h>
int main() {
char word[25];  
scanf("%s", word);
int z = 0, o = 0, i;
//(no. of  Zs and Os)
for (i = 0; word[i] != '\0'; i++) {
if (word[i] == 'Z' || word[i] == 'z') {
z++;
} else if (word[i] == 'O' || word[i] == 'o') {
 o++;
}
  }
if (o == 2 * z) {
printf("Yes");
} else {
printf("No");    }
 return 0;
}