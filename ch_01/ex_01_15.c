#include <stdio.h>
/* print Fahrenheit-Celsius table
for fahr = 0, 20, ..., 300 */

float ConvertToCelsius(float fahr);
int main() {
  float fahr;
  int lower, upper, step;
  lower = 0;
  upper = 300;
  step = 20;
  /* lower limit of temperature scale */
  /* upper limit */
  /* step size */

  fahr = lower;
  while (fahr <= upper) {
    printf("%.0f\t%.2f\n", fahr, ConvertToCelsius(fahr));
    fahr = fahr + step;
  }
}

float ConvertToCelsius(float fahr) { return 5 * (fahr - 32) / 9; }
