#include <ctype.h>
#include <stdio.h>
#include <stdlib.h> /* for atof() */
#include <string.h>

#define MAXOP 100  /* max size of operand or operator */
#define NUMBER '0' /* signal that a number was found */
#define MAXVAL 100 /* maximum depth of val stack */
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
int getop(char[]);
int getch(void);
void ungetch(int);
void ungets(char s[]);

/* reverse Polish calculator that uses command line */
int main(int argc, char *argv[]) {
    double op2;
    char s[MAXOP];
    while (--argc > 0) {
        ungets(" ");
        ungets(*++argv);
        switch (getop(s)) {
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
        default:
            printf("error: unknown command %s\n", s);
            argc = 1;
            break;
        }
    }
    printf("\t%.8g\n", pop());
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
int getch(void) /* get a (possibly pushed-back) character */
{
    return (bufp > 0) ? buf[--bufp] : getchar();
}

void ungetch(int c) /* push character back on input */
{
    if (bufp >= BUFSIZE)
        printf("ungetch: too many characters\n");
    else
        buf[bufp++] = c;
}

void ungets(char s[]) {
    int length = strlen(s);

    while (length > 0) {
        ungetch(s[--length]);
    }
}