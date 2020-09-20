#include <stdio.h>

int fib(int n)
{
  if (n <= 1)
    return n;

  return fib(n - 1) + fib(n - 2);
}

int main()
{
  int r = fib(5);
  printf("Fibonacci of 5: %d \n", r);

  r = fib(6);
  printf("Fibonacci of 6: %d \n", r);

  r = fib(7);
  printf("Fibonacci of 7: %d \n", r);
}