#include <stdio.h>

int power(int m, int n);

int power(int base, int n) {
  int p;

  for (p = 1; n > 0; --n) p = p * base;

  return p;
}
