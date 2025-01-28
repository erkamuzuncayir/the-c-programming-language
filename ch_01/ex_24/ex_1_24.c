#include <stdio.h>
#define LONGESTLINELENGTH 1000
#define OPEN 1
#define CLOSE 0

// Function to check if open and close characters match in a given string
int checkOpenClosingCharacter(char search[], char open, char close);
int getlines(char s[]);
int main() {
  int len;                      /* current line length */
  int max;                      /* maximum length seen so far */
  char line[LONGESTLINELENGTH]; /* current input line */

  while ((len = getlines(line)) > 0) {
    int result = checkOpenClosingCharacter(line, '(', ')');
    if (result != 0) printf("Parentheses cause syntax error!\n");
    result = checkOpenClosingCharacter(line, '{', '}');
    if (result != 0) printf("Curly braces cause syntax error!\n");
    result = checkOpenClosingCharacter(line, '[', ']');
    if (result != 0) printf("Brackets cause syntax error!\n");
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

int checkOpenClosingCharacter(char search[], char open, char close) {
  int c, i, count, state;
  i = count = state = 0;

  // Iterate over the string to count open and close characters
  while (search[i] != '\0') {
    if (search[i] == open) {
      // Increment count when open character is found
      count++;
    } else if (search[i] == close)
      // Decrement count when close character is found
      count--;

    i++;
  }
  // Return the final count, which indicates if open and close characters match
  return count;
}
