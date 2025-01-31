#include <stdio.h>
#define LONGESTLINELENGTH 100

int getLines(char s[]);
void expandShorthandNotation(char shorthand[], int shorthandLength, char expanded[]);
int main()
{
  int len;
  char shorthand[LONGESTLINELENGTH];
  while ((len = getLines(shorthand)) > 0) {
    shorthand[len] = '\0';
    char expanded[shorthand[len - 2] - shorthand[0]];
    expandShorthandNotation(shorthand, len, expanded);
    printf("Shorthand: %s\n", shorthand);
    printf("Expanded: %s\n", expanded);
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

void expandShorthandNotation(char shorthand[], int shorthandLength, char expanded[])
{
  int i = 0;
  for (; shorthand[0] + i != shorthand[shorthandLength - 2] + 1; i++) {
    expanded[i] = shorthand[0] + i;
  }
  expanded[i] = '\0';
}