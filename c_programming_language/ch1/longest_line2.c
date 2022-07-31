#include <stdio.h>

#define MAXLINE 1000 /* 允许的输入行的最大长度 */

int max;               /* 到目前为止发现的最长行的长度 */
char line[MAXLINE];    /* 当前的输入行 */
char longest[MAXLINE]; /* 用于保存最长的行 */

int gtline(void);
void copy(void);

/* 打印最长的输入行: 特别版本 */
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

  if (max > 0) /* 存在这样的行 */
    printf("%s\n", longest);

  return 0;
}

/* getline 函数: 特别版本 */
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

/* copy 函数: 特别版本 */
void copy() {
  int i = 0;
  extern char line[], longest[];
  while ((longest[i] = line[i]) != '\0') ++i;
}
