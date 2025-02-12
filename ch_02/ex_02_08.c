#include <stdio.h>

void printBinary(unsigned int num);
void printBinaryWithNewline(unsigned int num);
unsigned rightrot(unsigned base, unsigned int pos);
int main() {
  unsigned int base = 197;

  printf("Base: ");
  printBinaryWithNewline(base);

  unsigned res = rightrot(base, 2);
  printf("Right rotated: ");
  printBinaryWithNewline(res);
}

unsigned rightrot(unsigned base, unsigned int pos) {
  unsigned int inverted_base_mask = ~(~0 << (pos + 1));
  unsigned int inverted_base = base & inverted_base_mask;
  unsigned int base_new_rightmost = base >> (pos + 1);

  unsigned int temp = base_new_rightmost;
  int insert_digit_count = 0;
  while (temp) {
    temp >>= 1;
    insert_digit_count++;
  }
  inverted_base <<= insert_digit_count;
  inverted_base |= base_new_rightmost;
  return inverted_base;
}

void printBinary(unsigned int num) {
  if (num > 1) printBinary(num >> 1);

  printf("%d", num & 1);
}
void printBinaryWithNewline(unsigned int num) {
  printBinary(num);
  printf("\n");
}