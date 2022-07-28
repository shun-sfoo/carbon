#include <stdio.h>

#define CHARACTERS 26
#define MAXHIST    15

int main() {
  int nt, nl, ns, nother, maxvalue, i, c, len;
  nother = nt = nl = ns = 0;
  int chars[CHARACTERS] = {0};

  while ((c = getchar()) != EOF) {
    if (c == ' ')
      ++ns;
    else if (c == '\t')
      ++nt;
    else if (c == '\n')
      ++nl;
    else if (c >= 'a' && c <= 'z')
      ++chars[c - 'a'];
    else
      ++nother;
  }

  maxvalue = 0;
  for (i = 0; i < CHARACTERS; ++i) {
    if (chars[i] > maxvalue) maxvalue = chars[i];
  }

  for (i = 0; i < CHARACTERS; ++i) {
    if (chars[i] > 0) {
      if ((len = chars[i] * MAXHIST / maxvalue) <= 0) len = 1;

    } else
      len = 0;
    while (len > 0) {
      putchar('*');
      --len;
    }
    putchar('\n');
  }
}
