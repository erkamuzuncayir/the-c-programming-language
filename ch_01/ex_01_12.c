#include <stdio.h>

int main() {
  int c;
  while ((c = getchar()) != EOF) {
    if (c == ' ' || c == '\n' || c == '\t' || c == '\b')
      putchar('\n');
    else
      putchar(c);
  }
}
