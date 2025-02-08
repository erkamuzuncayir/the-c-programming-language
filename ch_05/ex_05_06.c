#include <stdio.h>
#include <string.h>

int getlines(char *sourcePtr, int limit);
void itoa(int n, char *sourcePtr);
void reverse(char *sourcePtr);
int strindex(char *sourcePtr, char *searchPtr);

int main() {
    char line[15];
    printf("%d, %s\n", getlines(line, 15), line);

    printf("%d \n", strindex("Testsearch", "a"));
}

int getlines(char *sourcePtr, int limit) {
    int ch, count;

    count = 0;
    while (limit > 0 && (ch = getchar()) != EOF && ch != '\n') {
        *sourcePtr++ = ch;
        count++;
    }
    if (ch == '\n') {
        *sourcePtr++ = ch;
        count++;
    }
    *sourcePtr = '\0';
    return count;
}

void itoa(int n, char *sourcePtr) {
    int count, sign;
    if ((sign = n) < 0)
        n = -(n + 1);
    count = 0;
    do {
        *sourcePtr++ = n % 10 + '0';
        count++;
    } while ((n /= 10) > 0);
    if (sign < 0) {
        *(sourcePtr - count) += 1;
        *sourcePtr++ = '-';
    }
    *sourcePtr = '\0';
    reverse(sourcePtr);
}

void reverse(char *sourcePtr) {
    int ch, i, j;
    for (i = 0, j = strlen(sourcePtr) - 1; i < j; i++, j--) {
        ch = *(sourcePtr + i);
        *(sourcePtr + i) = *(sourcePtr + j);
        *(sourcePtr + j) = ch;
    }
}

int strindex(char *sourcePtr, char *searchPtr) {
    int i, j, k;
    int foundIndex = -1;
    for (i = 0; *(sourcePtr + i) != '\0'; i++) {
        for (j = i, k = 0; *(searchPtr + k) != '\0'; j++, k++) {
            if (*(sourcePtr + j) == *(searchPtr + k) && i > foundIndex) {
                foundIndex = i;
            }
        }
    }
    if (foundIndex != -1)
        return foundIndex;

    return -1;
}