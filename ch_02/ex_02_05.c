#include <stdio.h>
#define LONGESTLINELENGTH 1000

int any(char search[], char find[]);
int getLines(char s[]);
int main() {
  char search[LONGESTLINELENGTH];
  char find[LONGESTLINELENGTH];
  while (getLines(search) > 0) {
    getLines(find);
    int result = any(search, find);
    printf("%d\n", result);
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

int any(char search[], char find[]) {
  int i, j, firstLocation;
  firstLocation = -1;
  for (i = 0; search[i] != '\0'; i++) {
    for (j = 0; find[j] != '\0'; j++) {
      if (find[i] != '\0' && find[j] == search[i] &&
          (firstLocation == -1 || i <= firstLocation)) {
        firstLocation = i;
      }
    }
  }
  return firstLocation;
}