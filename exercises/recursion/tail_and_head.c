#include <stdio.h>

void head(int n)
{
  if (n <= 0)
    return;

  head(n - 1);
  printf("%d ", n);
}

void tail(int n)
{
  if (n <= 0)
    return;

  printf("%d ", n);
  tail(n - 1);
}

int main()
{
  int x = 3;
  printf("\nHead recursion\n");
  head(x); // Prints out 1, 2, 3

  printf("\nTail recursion\n");
  tail(x); // Prints out 3, 2, 1
}