#include <stdio.h>
#define MAXLINE 1000 /* maximum input line length */
int getlines(char line[], int max);
int strindex(char source[], char searchfor[]);
char pattern[] = "ould"; /* pattern to search for */

/* find all lines matching pattern */
int main()
{
  char line[MAXLINE];
  int found = 0;

  while (getlines(line, MAXLINE) > 0) {
    int index = strindex(line, pattern);
    if (index >= 0) {
      printf("%d\n", index);
      found++;
    }
  }
  return found;
}
/* getline: get line into s, return length */
int getlines(char s[], int lim)
{
  int c, i;

  i = 0;
  while (--lim > 0 && (c=getchar()) != EOF && c != '\n') {
    s[i++] = c;
  }if (c == '\n') {
    s[i++] = c;
  }
  s[i] = '\0';
  return i;
}
/* strindex: return index of t in s, -1 if none */
int strindex(char s[], char t[])
{
  int i, j, k;
  int foundIndex = - 1;
  for (i = 0; s[i] != '\0'; i++) {
    for (j=i, k=0; t[k]!='\0'; j++, k++) {
      if (s[j]==t[k] && i > foundIndex) {
        foundIndex = i;
      }
    }
  }
  if (foundIndex != -1)
    return i;
  else
    return -1;
}