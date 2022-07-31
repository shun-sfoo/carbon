#include <stdio.h>

#define MAXHIST 15 /* max length of histogram */
#define MAXWORD 11 /* max length of a word */
#define IN      1  /* inside a word */
#define OUT     0  /* out side a word */

/* print vertical histogram */
int main() {
  int c, i, j, nc, state;
  int maxvalue;          /* maximum value for wl[] */
  int overflow;          /* number of overflow words */
  int wl[MAXWORD] = {0}; /* word length counters */

  state = OUT;
  nc = 0;       /* number of chars in a word */
  overflow = 0; /* number of words >= MAXWORD */

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
      nc = 1; /* beginnign of a new word */
    } else
      ++nc; /* inside a word */
  }

  maxvalue = 0;
  for (i = 1; i < MAXWORD; ++i)
    if (wl[i] > maxvalue) maxvalue = wl[i];

  for (i = MAXHIST; i > 0; --i) {
    for (j = 1; j < MAXWORD; ++j) {
      if (wl[j] * MAXHIST / maxvalue >= i)
        printf("   * ");
      else
        printf("     ");
    }
    putchar('\n');
  }

  for (i = 1; i < MAXWORD; ++i) printf("%4d ", i);
  putchar('\n');
  for (i = 1; i < MAXWORD; ++i) printf("%4d ", wl[i]);
  putchar('\n');
  if (overflow > 0) printf("There are %d words >= %d\n", overflow, MAXWORD);
}
