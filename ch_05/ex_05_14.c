#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAXLINES 5000
#define NUMERIC 1
#define DECREMENT 2
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

/* writelines: write output lines */
void writelines(char *lineptr[], int nlines, int decrement) {
    int i;
    if (decrement) {
        for (i = nlines - 1; i > 0; i--)
            printf("%s\n", lineptr[i]);
    } else {
        for (i = 0; i < nlines; i++)
            printf("%s\n", lineptr[i]);
    }
}
