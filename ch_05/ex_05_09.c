static char daytab[2][13] = {
    {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31},
    {0, 31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31}};

/* day_of_year: set day of year from month & day */
int day_of_year(int year, int month, int day) {
    int leap = year % 4 == 0 && year % 100 != 0 || year % 400 == 0;
    char *ptr = daytab[leap];
    while (--month)
        day += *++ptr;
    return day;
}

/* month_day: set month, day from day of year */
void month_day(int year, int yearday, int *pmonth, int *pday) {
    int leap = year % 4 == 0 && year % 100 != 0 || year % 400 == 0;
    char *ptr = daytab[leap];

    while (yearday > *++ptr)
        yearday -= *ptr;
    *pmonth = ptr - *(daytab + leap);
    *pday = yearday;
}
