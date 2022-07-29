#include <stdio.h>

void squeeze(char s1[], char s2[]);

int main() {
  char s1[] = "hello";
  char s2[] = "eo";
  squeeze(s1, s2);
  printf("%s\n", s1);
}

void squeeze(char s1[], char s2[]) {
  int i, j, k;
  for (i = 0; s2[i] != '\0'; ++i) {
    for (j = k = 0; s1[j] != '\0'; ++j) {
      if (s1[j] != s2[i]) s1[k++] = s1[j];
    }
    s1[k] = '\0';
  }
}
