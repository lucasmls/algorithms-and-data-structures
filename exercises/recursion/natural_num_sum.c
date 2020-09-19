#include <stdio.h>

int sum(int n)
{
  if (n <= 1)
    return 1;

  return sum(n - 1) + n;
}

int main()
{
  int r = sum(5); // Prints out: 15
  printf("Result: %d", r);
}