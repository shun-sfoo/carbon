#include <stdio.h>

#define MAXLINE 1000

int max;
char line[MAXLINE];
char longest[MAXLINE];

int gtline(void);
void copy(void);

int main() {
  int len;
  extern int max;
  extern char longest[];
  max = 0;

  while ((len = gtline()) > 0) {
    if (len > max) {
      max = len;
      copy();
    }
  }

  if (max > 0) printf("%s\n", longest);

  return 0;
}

int gtline() {
  int i, c;
  extern char line[];

  for (i = 0; i < MAXLINE - 1 && (c = getchar()) != EOF && c != '\n'; ++i)
    line[i] = c;

  if (c == '\n') {
    line[i] = c;
    ++i;
  }

  line[i] = '\0';
  return i;
}

void copy() {
  extern char line[];
  extern char longest[];
  int i = 0;
  while ((longest[i] = line[i]) != '\0') ++i;
}
