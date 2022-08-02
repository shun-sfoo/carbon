#include <stdio.h>

#define MAXCOL 60
#define TABINC 60

char line[MAXCOL];

int exptab(int pos);
int findblank(int pos);
int newpost(int pos);
void printl(int pos);

int main() {
  int c, pos;

  pos = 0;
  while ((c = getchar()) != EOF) {
    if (c == '\t') {
      pos = exptab(pos);
    } else if (c == '\n') {
      printl(pos);
      pos = 0;
    } else if (++pos >= MAXCOL) {
      pos = findblank(pos);
      printl(pos);
      pos = newpost(pos);
    }
  }
}

void printl(int pos) {
  int i;
  for (i = 0; i < pos; ++i) putchar(line[i]);
  if (pos > 0) putchar('\n');
}

int exptab(int pos) {
  line[pos] = ' ';
  for (++pos; pos < MAXCOL && pos % TABINC != 0; ++pos) line[pos] = ' ';
  if (pos < MAXCOL)
    return pos;
  else {
    printl(pos);
    return 0;
  }
}




