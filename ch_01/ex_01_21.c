#include <stdio.h>
#define LONGESTLINELENGTH 1000
#define TABLENGTH 8

void printOutputWithHex(char s[]);
int getLinesWithoutSpaces(char s[]);
int main() {
  int len;                      /* current line length */
  int max;                      /* maximum length seen so far */
  char line[LONGESTLINELENGTH]; /* current input line */

  while ((len = getLinesWithoutSpaces(line)) > 0) {
    printOutputWithHex(line);
  }
  return 0;
}

void printOutputWithHex(char s[]) {
  // Print each character in the string, replacing special characters with their
  // hex representations
  for (int i = 0; s[i] != '\0'; i++) {
    if (s[i] == '\t') {
      printf("\\t");
    } else if (s[i] == ' ') {
      printf("[SP]");
    } else if (s[i] == '\n') {
      printf("\\n");
    } else {
      printf("%c", s[i]);
    }
  }
  printf("\n");
}

int getLinesWithoutSpaces(char s[]) {
  int c;
  int i = 0;
  int spaceCount = 0;
  int tabCount = 0;
  // Read characters until end of line or file
  while ((c = getchar()) != EOF && c != '\n') {
    if (c == ' ') {
      // Count consecutive spaces
      spaceCount++;
    } else {
      // Replace consecutive spaces with tabs and spaces
      if (spaceCount >= TABLENGTH) {
        tabCount = spaceCount / TABLENGTH;
        spaceCount = spaceCount % TABLENGTH;
        for (; tabCount > 0; tabCount--) {
          s[i++] = '\t';
        }
      }
      // Add remaining spaces
      for (; spaceCount > 0; spaceCount--) {
        s[i++] = ' ';
      }
      // Add the current character
      s[i++] = c;
    }
  }
  // Add newline character if present
  if (c == '\n') {
    s[i] = c;
    ++i;
  }
  // Null-terminate the string
  s[i] = '\0';
  return i;
}
