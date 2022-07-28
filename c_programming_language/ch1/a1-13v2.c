#include <stdio.h>

#define MAXHIST 15 /* max length of histogram */
#define MAXWORD 11 /* max length of a word */
#define IN      1  /* inside a word */
#define OUT     0  /* out side a word */

int main() {
  int c, i, j, nc, state, overflow, maxvalue;
  int wl[MAXWORD] = {0};

  overflow = nc = 0;
  state = OUT;

  while ((c = getchar()) != EOF) {
    if (c == ' ' || c == '\t' || c == '\n') {
      state = OUT;
      if (nc > 0) {
        if (nc < MAXWORD)
          ++wl[nc];
        else
          ++overflow;
      }
    } else if (state == OUT) {
      state = IN;
      nc = 1;
    } else
      ++nc;
  }

  maxvalue = 0;
  for (i = 1; i < MAXWORD; i++) {
    if (wl[i] > maxvalue) maxvalue = wl[i];
  }

  for (i = MAXHIST; i > 0; --i) {
    for (j = 0; j < MAXWORD; ++j) {
      if (wl[j] * MAXHIST / maxvalue >= i) 
        printf(" * ");
      else 
        printf("   ");
    }
    putchar('\n');
  }
}
