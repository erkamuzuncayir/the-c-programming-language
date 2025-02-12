#include <stdio.h>
#define LONGESTLINELENGTH 1000
#define COMMENTON 1
#define COMMENTOFF 0

// Function to remove comments from a string
void removeComments(char s[], int length);

// Function to read a line into a string
int getlines(char s[]);

int main() {
  int len;                       // current line length
  int max;                       // maximum length seen so far
  char line[LONGESTLINELENGTH];  // current input line

  while ((len = getlines(line)) > 0) {
    removeComments(line, len);
    printf("%s", line);
  }
  return 0;
}

// Read a line into s, return length
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

// Remove comments from a string
void removeComments(char s[], int length) {
  int i, j, oneLineComment, multiLineComment;
  i = j = oneLineComment = multiLineComment = 0;

  // Loop through the string
  while (s[i] != '\0') {
    // Check if we are not in a comment
    if (oneLineComment == COMMENTOFF && multiLineComment == COMMENTOFF) {
      // Check for one-line comment
      if (s[i] == '/' && s[i + 1] == '/') oneLineComment = COMMENTON;
      // Check for multi-line comment
      else if (s[i] == '/' && s[i + 1] == '*')
        multiLineComment = COMMENTON;
      // If not in a comment, copy the character
      else
        s[j++] = s[i];
    }
    // If in a one-line comment, check for newline
    else if (oneLineComment == COMMENTON) {
      if (s[i] == '\n') oneLineComment = COMMENTOFF;
    }
    // If in a multi-line comment, check for end of comment
    else if (multiLineComment == COMMENTON) {
      if (s[i] == '*' && s[i + 1] == '/') {
        multiLineComment = COMMENTOFF;
        i++;
      }
    }
    i++;
  }

  // Null-terminate the string
  s[j] = '\0';
}
