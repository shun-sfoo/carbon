#include <stdio.h>

/* count blanks, tabs, and newlines */
int main() {
  int c, nb, nt, nl;
  nb = nt = nl = 0;
  while((c = getchar()) != EOF) {
    if (c == ' ') ++nb;
    if (c == '\n') ++nl;
    if (c == '\t') ++nt;
  }

  printf("%d %d %d\n", nb, nt, nl);
}
