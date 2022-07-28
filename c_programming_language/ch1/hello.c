#include <stdio.h>

int main() {
  printf("hello, world\n");

  printf(
      "hello,"
      " world\n");

  char str[] =
      "hello, "
      "world\n";

  printf("%s", str);
}
