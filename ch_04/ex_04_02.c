#include <ctype.h>
#include <stdio.h>
#include <tgmath.h>
double atof(char s[]) ;
int main() {
  char s[] = "3.14E-4";
  printf("%f\n", atof(s));
  return 0;
}

/* atof: convert string s to double */
double atof(char s[]) {
  double val, power;
  int i, sign;
  for (i = 0; isspace(s[i]); i++)/* skip white space */
    ;

  sign = (s[i] == '-') ? -1 : 1;
  if (s[i] == '+' || s[i] == '-')
    i++;
  for (val = 0.0; isdigit(s[i]); i++)
    val = 10.0 * val + (s[i] - '0');
  if (s[i] == '.')
    i++;
  for (power = 1.0; isdigit(s[i]); i++) {
    val = 10.0 * val + (s[i] - '0');
    power *= 10;
  }
  double res = sign * val / power;
  if (s[i] == 'e' || s[i] == 'E') {
    i++;
    int eSign;
    if (s[i] == '-') {
      eSign = -1;
      s++;
    } else
      eSign = 1;

    int eMult = 1;
    int digitCount = 0;
    int digitBase = 1;
    for (; isdigit(s[i]); i++) {
      digitCount++;
      if (digitCount > 1)
        digitBase *= 10;
    }
    i -= digitCount;
    for (; isdigit(s[i]); i++) {
      eMult = (s[i] - '0') * digitBase;
      digitBase /= 10;
    }
    if (eSign > 0) {
      while (eMult > 0) {
        res *= 10;
        eMult--;
      }
    }
    else
    {
      while (eMult > 0) {
        res /= 10;
        eMult--;
      }
    }
  }
  return res;
}