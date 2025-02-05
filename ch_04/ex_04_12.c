#include <stdio.h>
#include <string.h>
#define LONGESTLINELENGTH 100
void itoa(int n);
void reverse(char s[]);

static int i = 0;
static int sign = 1;
static char s[LONGESTLINELENGTH];

int main(){
  char s[LONGESTLINELENGTH];
  printf("%s\n", "55555");
  itoa(-254);
}

void itoa(int n)
{
  if (n > 0) {
    s[i++] = n % 10 + '0'; /* get next digit */
    n /= 10;
    itoa(n);
  }
  else if (n < 0) {
    sign = -1;
    itoa(-n);
  }
  else {
    if (sign == -1)
      s[i++] = '-';

    s[i] = '\0';
    reverse(s);
    printf("%s\n", s);
  }
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