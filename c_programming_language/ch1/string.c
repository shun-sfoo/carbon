int atoi(char s[]) {
  int i, n;
  n = 0;
  for (i = 0; s[i] >= '0' && s[i] <= '9'; ++i) n = 10 * n + (s[i] - '0');
  return n;
}

void squeeze(char s[], int c) {
  int i, j;
  for (i = j = 0; s[i] != '\0'; ++i) {
    if (s[i] != c) s[j++] = s[i];
  }
  s[j] = '\0';
}

void strcat(char s[], char t[]) {
  int i, j;
  i = j = 0;
  while (s[i] != '\0') ++i;

  while ((s[i++] = t[j++]) != '\0')
    ;
}
