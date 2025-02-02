#include <ctype.h>
#include <stdio.h>
#include <stdlib.h> /* for atof() */
#define MAXOP 100   /* max size of operand or operator */
#define NUMBER '0'  /* signal that a number was found */
#define MAXVAL 100  /* maximum depth of val stack */
#define BUFSIZE 100

int sp = 0;         /* next free stack position */
double val[MAXVAL]; /* value stack */
char buf[BUFSIZE];
int bufp = 0;

double add(double opOne, double opTwo);
double multiply(double opOne, double opTwo);
double subtract(double opOne, double opTwo);
double divide(double opOne, double opTwo);
int mod(int opOne, int opTwo);

void push(double);
double pop(void);
double peek(void);
void clear(void);
void duplicate(void);
void swap(void);

int getop(char[]);
int getch(void);
void ungetch(int);
/* reverse Polish calculator */
int main() {
  int type;
  double op2;
  char s[MAXOP];
  while ((type = getop(s)) != EOF) {
    switch (type) {
    case NUMBER:
      push(atof(s));
      break;
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
    case 'p':
      printf("peek: %f\n", peek());
      break;
    case 'c':
      clear();
      break;
    case 'd':
      duplicate();
      break;
    case 's':
      swap();
      break;
    case '\n':
      printf("\t%.8g\n", pop());
      break;
    default:
      printf("error: unknown command %s\n", s);
      break;
    }
  }
  return 0;
}

double add(double opOne, double opTwo) { return opOne + opTwo; }
double subtract(double opOne, double opTwo) { return opOne - opTwo; }
double multiply(double opOne, double opTwo) { return opOne * opTwo; }
double divide(double opOne, double opTwo) { return opOne / opTwo; }
int mod(int opOne, int opTwo) { return opOne % opTwo; }

/* push: push f onto value stack */
void push(double f) {
  if (sp < MAXVAL)
    val[sp++] = f;
  else
    printf("error: stack full, can't push %g\n", f);
}

/* pop: pop and return top value from stack */
double pop(void) {
  if (sp > 0)
    return val[--sp];
  else {
    printf("error: stack empty\n");
    return 0.0;
  }
}

double peek(void) {
  if (sp > 0)
    return val[sp];
  else {
    printf("error: stack empty\n");
    return 0.0;
  }
}

void clear(void) {
  sp = 0;
}

void duplicate(void) {
  double top = peek();
  if (top != 0.0)
    push(top);
}

void swap(void) {
  double tempOne = pop();
  double tempTwo = pop();
  push(tempOne);
  push(tempTwo);
}

/* getop: get next character or numeric operand */
int getop(char s[]) {
  int i, c, next;
  while ((s[0] = c = getch()) == ' ' || c == '\t')
    ;
  s[1] = '\0';
  if (!isdigit(c) && c != '.' && c != '-')
    return c; /* not a number */

  i = 0;
  if (c == '-') {
    next = getch();
    if (!isdigit(next) && next != '.') {
      ungetch(next);
      return c;
    }
    s[++i] = c = next;
  }

  if (isdigit(c)) /* collect integer part */
    while (isdigit(s[++i] = c = getch()))
      ;

  if (c == '.') /* collect fraction part */
    while (isdigit(s[++i] = c = getch()))
      ;

  s[i] = '\0';
  if (c != EOF)
    ungetch(c);

  return NUMBER;
}

/* buffer for ungetch */
/* next free position in buf */
int getch(void) /* get a (possibly pushed-back) character
                 */
{
  return (bufp > 0) ? buf[--bufp] : getchar();
}
void ungetch(int c)
/* push character back on input */
{
  if (bufp >= BUFSIZE)
    printf("ungetch: too many characters\n");
  else
    buf[bufp++] = c;
}