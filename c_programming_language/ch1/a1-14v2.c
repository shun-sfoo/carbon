#include <stdio.h>

#define CHARACTORS 26
#define MAXHIST    15

int main() {
  int c, i, j, maxvalue;
  int chars[CHARACTORS] = {0};

  while ((c = getchar()) != EOF) {
    if (c >= 'a' && c <= 'z') { ++chars[c - 'a']; }
  }

  maxvalue = 0;
  for (i = 0; i < CHARACTORS; ++i) {
    if (chars[i] > maxvalue) maxvalue = chars[i];
  }

  for (i = MAXHIST; i > 0; --i) {
    for (j = 0; j < CHARACTORS; ++j) {
      if (chars[j] * MAXHIST / maxvalue >= i)
        printf(" * ");
      else
        printf("   ");
    }
    putchar('\n');
  }
}
