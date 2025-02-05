#include <stdio.h>
#define LONGESTLINELENGTH 100
void itoa(int n, char s[], int length);
void reverse(char s[], int headIndex, int tailIndex);

int main(){
  char s[LONGESTLINELENGTH];
  printf("%s\n", "55555");
  itoa(-24, s, 5);
}

void itoa(int n, char s[], int length)
{
  int i, sign;
  if ((sign = n) < 0) /* record sign */
    n = -(n + 1);
  /* make n positive */
  i = 0;
  do {
    /* generate digits in reverse order */
    s[i++] = n % 10 + '0'; /* get next digit */
    length--;
  } while ((n /= 10) > 0);
  /* delete it */
  if (sign < 0) {
    s[0] += 1;
    s[i++] = '-';
  }
  while (length > 0) {
    s[i++] = ' ';
    length--;
  }
  s[i] = '\0';
  reverse(s, 0, i - 1);

  printf("%s\n", s);
}

void reverse(char s[], int headIndex, int tailIndex) {
  if (headIndex < tailIndex) {
    int temp = s[headIndex];
    s[headIndex] = s[tailIndex];
    s[tailIndex] = temp;
    reverse(s, ++headIndex, --tailIndex);
  }
}