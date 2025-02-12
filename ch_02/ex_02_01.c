#include <limits.h>
#include <stdio.h>
int main() {
  printf("Signed char min: %d\nSigned char max: %d\n", SCHAR_MIN, SCHAR_MAX);
  printf("Signed short min: %d\nSigned short max: %d\n", SHRT_MIN, SHRT_MAX);
  printf("Signed int min: %d\nSigned int max: %d\n", INT_MIN, INT_MAX);
  printf("Signed long min: %ld\nSigned long max: %ld\n", LONG_MIN, LONG_MAX);
  printf("Unsigned char max: %u\n", UCHAR_MAX);
  printf("Unsigned short max: %u\n", USHRT_MAX);
  printf("Unsigned int max: %u\n", UINT_MAX);
  printf("Unsigned long max: %lu\n", ULONG_MAX);
  return 0;
}