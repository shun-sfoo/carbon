#include <stdio.h>

int main() {
  char s[] = "test";
  int i, j;
  i = j = 0;
  while (s[i++] != '\0')
    ;

  printf("%d\n", i);  // => 5

  while (s[j] != '\0') ++j;

  printf("%d\n", j);  // => 4
}
