#include <stdio.h>

#define MAXLINE 1000

void reverse(char s[]);

int gtline(char line[], int maxline);

int main() {
  char line[MAXLINE];

  while (gtline(line, MAXLINE) > 0) {
    reverse(line);
    printf("%s", line);
  }
}

int gtline(char s[], int lim) {
  int c, i, j;
  j = 0;
  for (i = 0; (c = getchar()) != EOF && c != '\n'; ++i) {
    if (i < lim - 2) s[j++] = c;
  }

  if (c == '\n') {
    s[j++] = '\n';
    ++i;
  }

  s[j] = '\0';
  return i;
}

void reverse(char s[]) {
  int i, j;
  char temp;
  i = j = 0;
  while (s[j] != '\0') ++j;

  --j;
  if (s[j] == '\n') --j;

  while (j > i) {
    temp = s[i];
    s[i] = s[j];
    s[j] = temp;
    ++i;
    --j;
  }
}
