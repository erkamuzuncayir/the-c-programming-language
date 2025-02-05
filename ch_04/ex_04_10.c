#include <stdio.h>

#define MAXOP 100 /* max size of operand or operator */
#define NUMBER '0' /* signal that a number was found */
#define MAXVAL 100 /* maximum depth of val stack */
#define BUFSIZE 100

int sp = 0; /* next free stack position */
double val[MAXVAL]; /* value stack */
int buf[BUFSIZE];
int bufp = 0;

double add(double opOne, double opTwo);
double multiply(double opOne, double opTwo);
double subtract(double opOne, double opTwo);
double divide(double opOne, double opTwo);
int mod(int opOne, int opTwo);
void push(double);
double pop(void);
int getlines(char s[], int lim);
/* reverse Polish calculator */
int main() {
  double op2;
  char s[MAXOP];

  for (int i = 0; i < MAXOP; i++) {
    s[i] = 0;
  }
  getlines(s, MAXOP);
  for (int i = 0; s[i] != '\0'; i++){
    switch (s[i]) {
    case '+':
      push(add(pop(), pop()));
      break;
    case '*':
      push(multiply(pop(), pop()));
      break;
    case '-':
      op2 = pop();
      push(subtract(pop(), op2));
      break;
    case '/':
      op2 = pop();
      if (op2 != 0.0)
        push(divide(pop(), op2));
      else
        printf("error: zero divisor\n");
      break;
    case '%':
      op2 = pop();
      if (op2 != 0.0)
        push(mod(pop(), op2));
      else
        printf("error: zero divisor\n");
      break;
    case '\n':
      printf("\t%.8g\n", pop());
      break;
    default:
      if (s[i] >= '0' && s[i] <= '9')
        push(s[i] - '0');
      break;
    }
  }
  return 0;
}

double add(double opOne, double opTwo) {
  return opOne + opTwo;
}
double subtract(double opOne, double opTwo) {
return opOne - opTwo;
}
double multiply(double opOne, double opTwo) {
  return opOne * opTwo;
}
double divide(double opOne, double opTwo) {
return opOne / opTwo;
}
int mod(int opOne, int opTwo) {
return opOne % opTwo;
}

/* push: push f onto value stack */
void push(double f)
{
  if (sp < MAXVAL)
    val[sp++] = f;
  else
    printf("error: stack full, can't push %g\n", f);
}

/* pop: pop and return top value from stack */
double pop(void)
{
  if (sp > 0)
    return val[--sp];
  else {
    printf("error: stack empty\n");
    return 0.0;
  }
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