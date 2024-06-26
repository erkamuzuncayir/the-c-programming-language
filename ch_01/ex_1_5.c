#include <stdio.h>

#define LOWER = 0      /* lower limit of temperature scale */
#define UPPER = 300;    /* upper limit */
#define STEP = 20;      /* step size */

/* print Fahrenheit-Celsius table */
void ex_1_5()
{
    int fahr;

    for (fahr = UPPER; fahr > LOWER; fahr = fahr - STEP)
        printf("%3d %6.1f\n", fahr, (5.0/9.0)*(fahr-32));
}