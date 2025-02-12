#include <stdio.h>

void printBinary(unsigned int num);
void printBinaryWithNewline(unsigned int num);
unsigned bitcount(unsigned num);
int main() {
  unsigned int base = 197;

  printf("Base: ");
  printBinaryWithNewline(base);

  unsigned res = bitcount(base);
  printf("Digit Count: %d\n", res);
}

unsigned bitcount(unsigned num) {
  int bitCount;
  for (bitCount = 0; num != 0; num &= (num - 1)) {
    bitCount++;
  }
  return bitCount;
}

void printBinary(unsigned int num) {
  if (num > 1) printBinary(num >> 1);

  printf("%d", num & 1);
}
void printBinaryWithNewline(unsigned int num) {
  printBinary(num);
  printf("\n");
}