#include <stdio.h>

void ex_1_9()
{
    int c;
    int lastC = '\0';

    while((c = getchar()) != EOF)
    {
        if(c == '\n')
            printf(copiedLine);
        else
            copiedLine = copiedLine + c;
    }
}