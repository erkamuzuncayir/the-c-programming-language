#include <stdio.h>
#define MAXINPUTLENGTH 100

int strend(char *base, char *search);
int main() {
    char baseInput[MAXINPUTLENGTH];
    printf("Enter base: ");
    scanf("%s", baseInput);
    printf("\n");

    char searchInput[MAXINPUTLENGTH];
    printf("Enter search: ");
    scanf("%s", searchInput);

    printf("pos: %d\n", strend(baseInput, searchInput));
    return 0;
}

int strend(char *base, char *search) {
    while (*base++)
        ;
    while (*search++)
        ;

    base -= 2;
    search -= 2;

    while (*search) {
        if (*base-- != *search--)
            return 0;
    }

    return 1;
}