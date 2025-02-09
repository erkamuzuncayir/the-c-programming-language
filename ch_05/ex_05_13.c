#include <stdio.h>
#include <stdlib.h>

#define MAXLINELENGTH 100
#define DEFTAILLENGTH 10

int main(int argc, char *argv[]) {
    int tailLength = DEFTAILLENGTH;
    int wordStartIndex = 3;

    if (argc < 2) {
        wordStartIndex = 2;
    } else if (*argv[1] == '-' && *++argv[1] == 'n') {
        if (*argv[2] >= '0' && *argv[2] <= '9') {
            tailLength = atoi(argv[2]);
            if (tailLength < 0) {
                printf("Error: Invalid tail length!\n");
                return 1;
            }
        } else
            wordStartIndex = 2;
    } else {
        printf("Usage tail -n NUMBER!\n");
        return 1;
    }

    int inputLength = -1;
    char input[MAXLINELENGTH];
    char *inputPtr = input;
    while (wordStartIndex < argc) {
        while (*argv[wordStartIndex] != '\0') {
            *inputPtr++ = *argv[wordStartIndex]++;
            inputLength++;
        }
        inputLength++;
        *inputPtr++ = ' ';
        wordStartIndex++;
    }

    int printStartIndex = inputLength > tailLength ? inputLength - tailLength : 0;
    while (tailLength > 0 && printStartIndex < inputLength) {
        printf("%c", input[printStartIndex++]);
        tailLength--;
    }
}