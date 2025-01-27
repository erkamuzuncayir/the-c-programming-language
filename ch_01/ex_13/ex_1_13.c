#include <stdio.h>
#define MAX_WORD_COUNT 10
#define MAX_WORD_LENGTH 10

int main() {
  int c;
  int wordCount = 0;
  int wordLength = 0;
  int histogram[MAX_WORD_COUNT];

  for (int l = 0; l < MAX_WORD_COUNT; l++) {
    histogram[l] = 0;
  }

  while (wordCount <= MAX_WORD_COUNT && (c = getchar()) != EOF) {
    if (c == '\n' || c == ' ' || c == '\t') {
      histogram[wordCount] = wordLength;
      wordCount++;
      wordLength = 0;
    } else {
      wordLength++;
    }
  }

  for (int i = MAX_WORD_LENGTH; i >= 1; i--) {
    printf("%d ", i);
    for (int j = 0; j < MAX_WORD_COUNT; j++) {
      if (histogram[j] == i) printf("%c ", 'N');
    }
    printf("\n");
  }
  return 0;
}
