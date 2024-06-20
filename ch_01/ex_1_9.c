#include <stdio.h>

#define NONBLANK 'a'

void ex_1_9()
{
    int c;
    int lastC = NONBLANK;

    while ((c = getchar()) != EOF)
    {
        if (c != ' ')
            putchar(c);
        else if (lastC != ' ')
            putchar(c);
        lastC = c;
    }
}