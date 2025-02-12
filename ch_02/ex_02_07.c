#include <stdio.h>

void printBinary(unsigned int num);
void printBinaryWithNewline(unsigned int num);
unsigned invert(unsigned base, unsigned int pos, unsigned int count);
int main() {
  unsigned int base = 197;

  printf("Base: ");
  printBinaryWithNewline(base);

  unsigned res = invert(base, 5, 3);
  printf("Inverted: ");
  printBinaryWithNewline(res);
}

unsigned invert(unsigned base, unsigned int pos, unsigned int count) {
  unsigned int base_rightmost_unchanged_mask = ~(~0 << (pos + 1 - count));
  unsigned int base_rightmost_unchanged = base & base_rightmost_unchanged_mask;
  unsigned int base_from_pos_to_right_mask = ~(~0 << (pos + 1));
  unsigned int base_from_pos_to_right = base & base_from_pos_to_right_mask;
  unsigned int base_invert_bits =
      ~(base_from_pos_to_right >> (pos + 1 - count)) & ~(~0 << (pos + 1 - count));
  base >>= pos + 1;
  base <<= count;
  base |= base_invert_bits;
  base <<= pos + 1 - count;
  base |= base_rightmost_unchanged;
  return base;
}

void printBinary(unsigned int num) {
  if (num > 1) printBinary(num >> 1);

  printf("%d", num & 1);
}
void printBinaryWithNewline(unsigned int num) {
  printBinary(num);
  printf("\n");
}