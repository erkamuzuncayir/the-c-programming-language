#include <stdio.h>

/* print Celsius-Fahrenheit table
    for celsius = 0, 20, ... , 300; floating point version */

int main() {
  float celsius, fahr;
  float lower, upper, step;

  lower = 0;   /* lower limit of temperature scale */
  upper = 300; /* upper limit */
  step = 20;   /* step size */

  printf("Celsius-Fahrenheit Table\n");

  celsius = lower;
  while (celsius <= upper) {
    fahr = (celsius * 9.0 / 5.0) + 32.0;
    printf("%3.1f %6.0f\n", celsius, fahr);
    celsius = celsius + step;
  }
}
