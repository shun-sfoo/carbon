#include <stdio.h>

#define LIMIT 4
#define IN    1
#define OUT   0

char show(const char s[LIMIT]);

int main() {
  char s[LIMIT] = {0};
  int c, state, nc;

  nc = 0;
  state = OUT;

  while ((c = getchar()) != EOF) {
    if (c == ' ' || c == '\t' || c == '\n') {
      if (state == IN) printf("%c\n", show(s));
      nc = 0;
      state = OUT;
    } else if (state == OUT) {
      state = IN;
      s[nc++] = c;
    } else {
      s[nc++] = c;
    }
  }
}

int atoi(const char s[]) {
  int i = 0;
  int n = 0;
  for (i = 0; s[i] >= '0' && s[i] <= '9'; ++i) n = 10 * n + (s[i] - '0');

  return n;
}

char show(const char s[]) {
  int r = atoi(s);
  return r - '\0';
}
