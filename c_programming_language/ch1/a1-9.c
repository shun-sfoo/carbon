#include <stdio.h>

#define NOBLANK 'a'
/* replace string of blanks with a single blank */
int main() {
  int c, lastc;
  lastc = NOBLANK;
  while((c=getchar()) != EOF) {
    if (c != ' ') putchar(c);
    if (c == ' ') 
      if (lastc != ' ') putchar(c);
    lastc = c;
  }
}
