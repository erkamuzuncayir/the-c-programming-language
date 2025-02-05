#include <stdio.h>
#define swap(t, x, y) {   t z;    \
                          z = x;  \
                          x = y;  \
                          y = z;  }

int main() {
  int i = 0;
  int j = 1;
  printf("before swap %d %d \n", i , j);
  swap(int, i, j);
  printf("after swap %d %d \n", i , j);

}