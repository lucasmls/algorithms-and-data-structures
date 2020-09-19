#include <stdio.h>

int factorial(int n)
{
  if (n <= 1)
    return 1;

  return factorial(n - 1) * n;
}

int main()
{
  int r = factorial(5);
  printf("The factorial of 5 is: %d\n", r);
  r = factorial(6);
  printf("The factorial of 6 is: %d\n", r);
}