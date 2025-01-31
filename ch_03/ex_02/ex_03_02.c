#include <stdio.h>
#define LONGESTLINELENGTH 100

int getLines(char s[]);
void makeEscapeSequencesVisible(char base[], char visible[]);
int main()
{
  int len;
  char line[LONGESTLINELENGTH];
  while ((len = getLines(line)) > 0) {
    line[len] = '\0';
    char lineWithVisibleEscapeSequences[len];
    makeEscapeSequencesVisible(line, lineWithVisibleEscapeSequences);
    printf("%s\n", line);
    printf("%s\n", lineWithVisibleEscapeSequences);
  }
  return 0;
}

int getLines(char s[]) {
  int c, i;
  for (i = 0; (c = getchar()) != EOF && c != '\n'; ++i) {
    s[i] = c;
  }
  if (c == '\n') {
    s[i] = c;
    ++i;
  }
  s[i] = '\0';
  return i;
}

void makeEscapeSequencesVisible(char base[], char visible[])
{
  int i = 0;
  int j = 0;
  while (base[i] != '\0') {
    switch (base[i]) {
      case '\t':
        visible[j++] = '\\';
        visible[j++] = 't';
        i++;
        break;
    case '\n':
      visible[j++] = '\\';
      visible[j++] = 'n';
      i++;
      break;
    case '\r':
      visible[j++] = '\\';
      visible[j++] = 'r';
      i++;
      break;
    default:
      visible[j++] = base[i++];
      break;
    }
  }
}