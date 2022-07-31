#include <stdio.h>

#define MAXLINE  1000 /* maximum input line size */
#define LONGLINE 80

int gtline(char line[], int maxline);

/* print lines longer than LONGLINE */
int main() {
  int len; /* current line length */
  int max; /* current input line */

  char line[MAXLINE];

  while ((len = gtline(line, MAXLINE)) > 0) {
    if (len >= 80) printf("%s", line);
  }
}

int gtline(char s[], int lim) {
  int c, i, j;
  j = 0;
  for (i = 0; (c = getchar()) != EOF && c != '\n'; ++i) {
    if (i < lim - 2) s[j++] = c;
  }

  if (c == '\n') {
    s[j++] = c;
    ++i;
  }

  s[j] = '\0';
  return i;
}
