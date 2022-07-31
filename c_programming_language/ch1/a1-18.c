#include <stdio.h>

#define MAXLINE 1000

int gtline(char line[], int maxline);
int rmove(char s[]);

int main() {
  int len;
  char line[MAXLINE];
  while ((len = gtline(line, MAXLINE)) > 0) {
    if (rmove(line) > 0) printf("%s", line);
  }
  return 0;
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

int rmove(char s[]) {
  int i;

  i = 0;
  while (s[i++] != '\n') /* find newline character */
    ;

  --i; /* back off from '\n' */
  while (i >= 0 && (s[i] == '\t' || s[i] == ' ')) --i;

  if (i >= 0) {    /* is it a noblank line? */
    s[++i] = '\n'; /* put newline character back */
    s[++i] = '\0'; /* terminal the string */
  }

  return i;
}
