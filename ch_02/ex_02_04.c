#include <stdio.h>
#define LONGESTLINELENGTH 1000

void squeeze(char search[], char find[]);
int getLines(char s[]);
int main() {
  char search[LONGESTLINELENGTH];
  char find[LONGESTLINELENGTH];
  while (getLines(search) > 0) {
    getLines(find);
    squeeze(search, find);
    printf("%s\n", search);
  }
  return 0;
}

int getLines(char s[]) {
  int c, i;
  for (i = 0; (c = getchar()) != EOF && c != '\n'; ++i) {
    s[i] = c;
  }
  if (c == '\n') {
    s[i] = c;
    ++i;
  }
  s[i] = '\0';
  return i;
}

void squeeze(char search[], char find[]) {
  int i, j, k;
  for (i = k = 0; search[i] != '\0'; i++) {
    for (j = 0; find[j] != '\0' && find[j] != search[i]; j++) {
      ;
    }
    if (find[j] == '\0') {
      search[k++] = search[i];
    }
  }
  search[k] = '\0';
}