#include <stdio.h>
#define LONGESTLINELENGTH 1000
#define TABLENGTH 4

int getLinesWithoutTabs(char s[]);
int main() {
  int len;                      /* current line length */
  char line[LONGESTLINELENGTH]; /* current input line */

  while ((len = getLinesWithoutTabs(line)) > 0) {
    printf("%s", line);
  }
  return 0;
}
/* getline: read a line into s, return length
 */
int getLinesWithoutTabs(char s[]) {
  int c, i;
  for (i = 0; (c = getchar()) != EOF && c != '\n'; ++i) {
    if (c == '\t') {
      for (int j = 0; j < TABLENGTH; ++j) {
        s[i] = ' ';
        ++i;
      }
      --i; /* Removing unnecessary incrementation */
    } else {
      s[i] = c;
    }
  }
  if (c == '\n') {
    s[i] = c;
      ++i;
  }
  s[i] = '\0';
  return i;
}