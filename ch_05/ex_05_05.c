#include <stdio.h>
#define MAXINPUTLENGTH 100

void strncpy(char *source, char *copy, int characterAmount);
void strncat(char *source, char *postfix, int characterAmount);
int strncmp(char *source, char *diff, int characterAmount);

int main() {
    char copySourceInput[MAXINPUTLENGTH];
    printf("Enter source to copy: ");
    scanf("%s", copySourceInput);

    int characterAmount = 0;
    printf("Enter character amount: ");
    scanf("%d", &characterAmount);

    char copiedOutput[MAXINPUTLENGTH];
    strncpy(copySourceInput, copiedOutput, characterAmount);
    printf("Copied output: %s\n", copiedOutput);

    //        --        //

    char catSourceInput[MAXINPUTLENGTH];
    printf("Enter source to concatenation: ");
    scanf("%s", catSourceInput);

    char catPostfixInput[MAXINPUTLENGTH];
    printf("Enter postfix: ");
    scanf("%s", catPostfixInput);

    printf("Enter character amount: ");
    scanf("%d", &characterAmount);

    printf("pre: %s\n", catSourceInput);
    strncat(catSourceInput, catPostfixInput, characterAmount);
    printf("post: %s\n", catSourceInput);

    //        --        //

    char compareSourceInput[MAXINPUTLENGTH];
    printf("Enter source to compare: ");
    scanf("%s", compareSourceInput);

    char diffInput[MAXINPUTLENGTH];
    printf("Enter diff: ");
    scanf("%s", diffInput);

    printf("Enter character amount: ");
    scanf("%d", &characterAmount);

    printf("Result: %d\n", strncmp(compareSourceInput, diffInput, characterAmount));
    return 0;
}

void strncpy(char *source, char *copy, int characterAmount) {
    while (characterAmount-- > 0 && *source)
        *copy++ = *source++;

    *copy = '\0';
}

void strncat(char *source, char *postfix, int characterAmount) {
    while (*source++ != '\0') {
        ;
    }
    *source--;
    while (*postfix != '\0' && characterAmount > 0) {
        *source++ = *postfix++;
        characterAmount--;
    }
    *source = '\0';
}

int strncmp(char *source, char *diff, int characterAmount) {
    while (characterAmount-- > 0 && *source && *diff) {
        if (*source < *diff)
            return -1;
        if (*source++ > *diff++)
            return 1;
    }
    if (*source && !*diff)
        return 1;
    if (!*source && *diff)
        return -1;
    return 0;
}