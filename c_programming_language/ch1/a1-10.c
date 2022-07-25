#include <stdio.h>

/* replace tabs and backspaces with visible characters */
int main() {
  int c;
  while ((c = getchar()) != EOF) {
    if (c == ' ')printf("\\b");
    if (c == '\t')printf("\\t");
    if (c == '\\')printf("\\\\");
    if (c!= ' ')
      if (c != '\t')
        if (c != '\\')
          putchar(c);
  }
}
