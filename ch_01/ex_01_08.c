#include <stdio.h>

int main() {
  int c = 0;
  char blankCount, tabCount, newlineCount;

  blankCount = 0;
  tabCount = 0;
  newlineCount = 0;

  while ((c = getchar()) != EOF) {
    if (c == '\n')
      newlineCount++;
    else if (c == '\t')
      tabCount++;
    else if (c == ' ')
      blankCount++;
  }

  printf("Newline count: %d\n", newlineCount);
  printf("Tab count: %d\n", tabCount);
  printf("Blank count: %d\n", blankCount);
}
