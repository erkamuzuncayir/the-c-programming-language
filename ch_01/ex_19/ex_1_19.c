#include <stdio.h>
#define LONGESTLINELENGTH 1000

int getlines(char s[]);
void reverse(char s[], int length);
int main() {
  int len;                      /* current line length */
  int max;                      /* maximum length seen so far */
  char line[LONGESTLINELENGTH]; /* current input line */

  while ((len = getlines(line)) > 0) {
    reverse(line, len);
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

void reverse(char s[], int length) {
  char temp;
  int j = 0;

  for (int i = length - 2; i > j; --i) {
    temp = s[i];
    s[i] = s[j];
    s[j] = temp;
    ++j;
  }
}
