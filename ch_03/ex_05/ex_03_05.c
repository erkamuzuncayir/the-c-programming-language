#include <limits.h>
#include <stdio.h>
#include <string.h>
#define LONGESTLINELENGTH 100
void itob(int n, char s[], int b);
void reverse(char s[]);

int main(){
  char s[LONGESTLINELENGTH];
  itob(32, s, 2);
}

void itob(int n, char s[], int b)
{
  int i, sign;
  if ((sign = n) < 0) /* record sign */
    n = -(n + 1);
  /* make n positive */
  i = 0;
  do {
    /* generate digits in reverse order */
    s[i++] = n % b + '0'; /* get next digit */
  } while ((n /= b) > 0);
  /* delete it */
  if (sign < 0) {
    s[0] += 1;
    s[i++] = '-';
  }
  s[i] = '\0';
  reverse(s);

  printf("%s\n", s);
}

void reverse(char s[])
{
  int c, i, j;
  for (i = 0, j = strlen(s)-1; i < j; i++, j--) {
    c = s[i];
    s[i] = s[j];
    s[j] = c;
  }
}