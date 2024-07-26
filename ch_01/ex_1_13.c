#include <stdio.h>

void ex_1_13()
{
    int c;
    int wordCount = 0;
    int barLength;
    int oldHistogram[wordCount];
    int currentHistogram[wordCount];

    while ((c = getchar()) != EOF)
    {
        if (c != '\n' || c != ' ')
        {
            ++barLength;
        }
        else
        {
            currentHistogram[wordCount];
            for (int i = 0; i < wordCount - 1; i++)
            {
                currentHistogram[i] = oldHistogram[i];
            }
            ++wordCount;
            currentHistogram[wordCount - 1] = barLength;
            barLength = 0;
        }
    }

    for (int i = 0; i < wordCount; i++)
    {
        printf("%d", currentHistogram[i]);
    }
    
}