#include <stdio.h>
#define NONBLANK 'a'

int main() {
  int c;
  int lastC = NONBLANK;

  while ((c = getchar()) != EOF) {
    if (c != ' ')
      putchar(c);
    else if (lastC != ' ')
      putchar(c);
    lastC = c;
  }
}
