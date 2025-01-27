#include <stdio.h>
#define MAX_WORD_COUNT 10
#define ALPHABET_LENGTH 26

int main() {
  char c;
  int wordCount = 0;
  int wordLength = 0;
  int histogram[ALPHABET_LENGTH];

  for (int l = 0; l < ALPHABET_LENGTH; l++) {
    histogram[l] = 0;
  }

  while (wordCount <= MAX_WORD_COUNT && (c = getchar()) != EOF) {
    if (c == '\n' || c == ' ' || c == '\t') {
      wordCount++;
    } else {
      int p = c - 97;
      histogram[c - 97]++;
    }
  }

  for (int i = 0; i < ALPHABET_LENGTH; i++) {
    printf("%c: %d\n", 97 + i, histogram[i]);
  }
  return 0;
}
