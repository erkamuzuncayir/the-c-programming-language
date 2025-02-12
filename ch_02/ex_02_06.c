#include <stdio.h>

void printBinary(unsigned int num);
void printBinaryWithNewline(unsigned int num);
unsigned copybits(unsigned modify, unsigned int pos, unsigned int count,
                  unsigned int base);
int main() {
  unsigned int modify = 172;
  unsigned int base = 197;
  printf("modify: ");
  printBinaryWithNewline(modify);
  printf("base: ");
  printBinaryWithNewline(base);

  unsigned res = copybits(modify, 4, 3, base);
  printBinaryWithNewline(res);
}

unsigned copybits(unsigned modify, unsigned int pos, unsigned int count,
                  unsigned int base) {
  unsigned int base_rightmost_mask = ~(~0 << count);
  unsigned int base_rightmost = base & base_rightmost_mask;
  unsigned int modify_rightmost_unchanged_mask = ~(~0 << (pos + 1 - count));
  unsigned int modify_rightmost_unchanged =
      modify & modify_rightmost_unchanged_mask;
  modify >>= pos + 1;
  modify <<= count;
  modify |= base_rightmost;
  modify <<= pos + 1 - count;
  modify |= modify_rightmost_unchanged;
  return modify;
}

void printBinary(unsigned int num) {
  if (num > 1) printBinary(num >> 1);

  printf("%d", num & 1);
}
void printBinaryWithNewline(unsigned int num) {
  printBinary(num);
  printf("\n");
}