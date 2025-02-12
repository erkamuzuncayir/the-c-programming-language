#include <stdio.h>
#include <math.h>
#define LONGESTLINELENGTH 1000
#define HEXADECIMAL 16

int convertHexToDecimal(char s[]);
int main() {
  int decimalNumber;                         /* current line length */
  int max;                                   /* maximum length seen so far */
  char hexadecimalNumber[LONGESTLINELENGTH]; /* current input line */

  while ((decimalNumber = convertHexToDecimal(hexadecimalNumber)) > 0)
    printf("%d", decimalNumber);
  return 0;
}

int convertHexToDecimal(char s[]) {
  int isPrefixReceived, digitCount;
  int input = isPrefixReceived = digitCount = 0;
  int skipDigitCount = 2;
  while ((input = getchar()) != EOF && input != '\n') {
    if (skipDigitCount != 0) {
      skipDigitCount--;
    } else {
      s[digitCount++] = input;
    }
  }

  int result = 0;
  int digitMultiplier = 1;
  for (int i = 0; i < digitCount; i++) {
    digitMultiplier = pow(HEXADECIMAL, i);
    if (s[i] == 'A' || s[i] == 'a')
      result += (10 * digitMultiplier);
    else if (s[i] == 'B' || s[i] == 'b')
      result += (11 * digitMultiplier);
    else if (s[i] == 'C' || s[i] == 'c')
      result += (12 * digitMultiplier);
    else if (s[i] == 'D' || s[i] == 'd')
      result += (13 * digitMultiplier);
    else if (s[i] == 'E' || s[i] == 'e')
      result += (14 * digitMultiplier);
    else if (s[i] == 'F' || s[i] == 'f')
      result += (15 * digitMultiplier);
    else
      result += (s[i] * digitMultiplier);
  }
  return result;
}