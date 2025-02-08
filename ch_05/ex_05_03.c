#include <stdio.h>
#define MAXINPUTLENGTH 100

void strncat(char *base, char *postfix);
int main() {
    char baseInput[MAXINPUTLENGTH];
    printf("Enter base: ");
    scanf("%s", baseInput);
    printf("\n");

    char postfixInput[MAXINPUTLENGTH];
    printf("Enter postfix: ");
    scanf("%s", postfixInput);

    printf("pre: %s\n", baseInput);
    strncat(baseInput, postfixInput);
    printf("post: %s\n", baseInput);
    return 0;
}

void strncat(char *base, char *postfix) {
    while (*base++ != '\0') {
        ;
    }
    *base--;
    while (*postfix != '\0') {
        *base++ = *postfix++;
    }
    *base = '\0';
}