#include <ctype.h>
#include <stdio.h>
#define BUFSIZE 100

int getfloat(double *pn);
double getch(void);
void ungetch(double);

char buf[BUFSIZE];
int bufp = 0;

int main(void) {
    double test = 1.0f;
    while (getfloat(&test) != EOF) {
        printf("%f\n", test);
    }
    return 0;
}

int getfloat(double *pn) {
    double c, temp, sign, power;
    power = 1.0;
    while (isspace(c = getch())) /* skip white space */
        ;
    if (!isdigit(c) && c != EOF && c != '+' && c != '-' && c != '.') {
        ungetch(c); /* it is not a number */
        return 0;
    }
    sign = (c == '-') ? -1 : 1;
    if (c == '+' || c == '-') {
        temp = c;
        if (!isdigit(c = getch())) {
            if (c != EOF)
                ungetch(c);
            ungetch(temp);
            return temp;
        }
    }
    for (*pn = 0; isdigit(c); c = getch())
        *pn = 10.0 * *pn + (c - '0');

    if (c == '.') {
        c = getch();
        for (power = 1.0; isdigit(c); c = getch()) {
            *pn = 10.0 * *pn + (c - '0');
            power *= 10.0;
        }
    }
    *pn *= sign / power;

    if (c != EOF)
        ungetch(c);
    return c;
}

/* buffer for ungetch */
/* next free position in buf */
/* get a (possibly pushed-back) character */
double getch(void) {
    return (bufp > 0) ? buf[--bufp] : getchar();
}

/* push character back on input */
void ungetch(double c) {
    if (bufp >= BUFSIZE)
        printf("ungetch: too many characters\n");
    else
        buf[bufp++] = c;
}