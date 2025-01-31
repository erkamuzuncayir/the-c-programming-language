#include <stdio.h>
int binsearch(int x, int list[], int listLength);
int main()
{
  int list[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
  int listLength = sizeof(list) / sizeof(list[0]);
  int x;
  printf("Please enter the number you want to search for: ");
  scanf("%d", &x);
  int result = binsearch(x, list, listLength);
  if (result == -1)
          printf("No match found.\n");
  else
          printf("Match found at index %d.\n", result);
  return 0;
}
/* binsearch: find x in v[0] <= v[1] <= ... <= v[n-1] */
int binsearch(int x, int list[], int listLength) {
  int low, high, mid;
  low = 0;
  high = listLength - 1;
  mid = (low + high) / 2;
  while (low <= high && x != list[mid]) {
    if (x < list[mid])
      high = mid + 1;
    else
      low = mid + 1;

    mid = (low + high) / 2;
  }
  if (x == list[mid])
    return mid;
  else
    return -1;
}