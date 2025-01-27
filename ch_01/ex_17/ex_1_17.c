#include <stdio.h>
#define LONGESTLINELENGTH 1000
#define SHORTESTLINELENGTH 80

int getlines(char s[]);
int main() {
  int len;                      /* current line length */
  int max;                      /* maximum length seen so far */
  char line[LONGESTLINELENGTH]; /* current input line */

  while ((len = getlines(line)) > 0)
    if (len > SHORTESTLINELENGTH) {
      printf("%s", line);
    }
  return 0;
}
/* getline: read a line into s, return length
 */
int getlines(char s[]) {
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
