#include <stdio.h>

int calculated_values[10];

int fib(int n)
{
  if (n <= 1)
  {
    calculated_values[n] = n;
    return n;
  }

  if (calculated_values[n - 2] == -1)
  {
    calculated_values[n - 2] = fib(n - 2);
  }

  if (calculated_values[n - 1] == -1)
  {
    calculated_values[n - 1] = fib(n - 1);
  }

  return calculated_values[n - 1] + calculated_values[n - 2];
}

int main()
{
  // Initializing the memoized values store.
  for (int i = 0; i <= 10; i++)
    calculated_values[i] = -1;
 
  int r = fib(5);
  printf("Fibonacci of 5: %d \n", r);

  r = fib(6);
  printf("Fibonacci of 6: %d \n", r);

  r = fib(7);
  printf("Fibonacci of 7: %d \n", r);
}