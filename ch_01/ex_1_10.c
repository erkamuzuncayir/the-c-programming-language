#include <stdio.h>

void ex_1_10()
{
    int c;

    while((c = getchar()) != EOF)
    {
        if(c == '\t')
            printf("\\t");
        else if(c == '\b')
            printf("\\b");
        else if(c == '\\')
            printf("\\\\");
        else
            putchar(c);
    }
}