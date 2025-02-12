#include <stdio.h>
#define LONGESTLINELENGTH 1000
#define WRAPLENGTH 10

// Function to append a word to the base string
int appendWord(char base[], char add[], int baseEndIndex);

// Function to read a line from input and wrap it at WRAPLENGTH
int getlines(char s[]);

int main() {
  int len;                      /* current line length */
  int max;                      /* maximum length seen so far */
  char line[LONGESTLINELENGTH]; /* current input line */

  // Read and print lines until end of file
  while ((len = getlines(line)) > 0) {
    printf("%s", line);
  }
  return 0;
}

// getline: read a line into s, return length
int getlines(char s[]) {
  int c, endIndexOfWord, currentLineLength, baseEndIndex;
  c = endIndexOfWord = currentLineLength = baseEndIndex = 0;
  char word[WRAPLENGTH];

  // Read characters until end of line or file
  while ((c = getchar()) != EOF && c != '\n') {
    if (c != ' ') {
      // Add character to current word
      if (endIndexOfWord < WRAPLENGTH - 1) {
        word[endIndexOfWord++] = c;
      }
    } else {
      // End of word, append to line
      word[endIndexOfWord++] = '\0';
      if (currentLineLength + endIndexOfWord > WRAPLENGTH) {
        // Line too long, start new line
        s[baseEndIndex++] = '\n';
        currentLineLength = 0;
      }
      baseEndIndex = appendWord(s, word, baseEndIndex);
      s[baseEndIndex++] = ' ';
      currentLineLength = currentLineLength + endIndexOfWord + 1;
      endIndexOfWord = 0;
    }
  }

  // Append last word to line
  if (endIndexOfWord > 0) {
    word[endIndexOfWord] = '\0';
    if (currentLineLength + endIndexOfWord > WRAPLENGTH) {
      // Line too long, start new line
      s[baseEndIndex++] = '\n';
    }
    baseEndIndex = appendWord(s, word, baseEndIndex);
  }

  // Null-terminate line
  s[baseEndIndex] = '\0';
  return baseEndIndex;
}

// Function to append a word to the base string
int appendWord(char base[], char add[], int baseEndIndex) {
  int i = 0;
  while (add[i] != '\0') {
    base[baseEndIndex++] = add[i++];
  }
  base[baseEndIndex] = '\0';
  return baseEndIndex;
}
