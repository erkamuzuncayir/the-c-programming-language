#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAXLINES 5000
#define NUMERIC 1
#define DECREMENT 2
#define FOLD 4
#define DIRECTORY 8
char *lineptr[MAXLINES];

int readlines(char *lineptr[], int nlines);
void writelines(char *lineptr[], int nlines, int decrement);
void quicksort(void *lineptr[], int left, int right, int isReverse, int (*comp)(void *, void *));
int numcmp(char *, char *);

static char options = 0;

/* sort input lines */
int main(int argc, char *argv[]) {
    int nlines; /* number of input lines read */
    char ch;

    while (--argc > 0 && (*++argv)[0] == '-') {
        while (ch = *++argv[0]) {
            switch (ch) {
            case 'n':
                options |= NUMERIC;
                break;
            case 'r':
                options |= DECREMENT;
                break;
            case 'f':
                options |= FOLD;
                break;
            case 'd':
                options |= DIRECTORY;
            default:
                printf("Illegal option %c!\n", ch);
            }
        }
    }

    if ((nlines = readlines(lineptr, MAXLINES)) >= 0) {
        quicksort((void **)lineptr, 0, nlines - 1, 0, (int (*)(void *, void *))(options & NUMERIC ? numcmp : strcmp));
        writelines(lineptr, nlines, options & DECREMENT);
        return 0;
    } else {
        printf("input too big to sort\n");
        return 1;
    }
}

int strcmp(char *s, char *t) {
    int fold = (options & FOLD) ? 1 : 0;
    int dir = (options & DIRECTORY) ? 1 : 0;
    if (dir) {
        while (*s != '\0' && *t != '\0') {
            while (!isalnum(*s))
                s++;
            while (!isalnum(*t))
                t++;
            char chOne = fold ? tolower(*s) : *s;
            s++;
            char chTwo = fold ? tolower(*t) : *t;
            t++;
            if (chOne == chTwo && chOne == '\0') {
                return 0;
            }
        }
    } else {
        for (; tolower(*s) == tolower(*t); s++, t++)
            if (*s == '\0')
                return 0;

        return *s - *t;
    }
    return *s - *t;
}