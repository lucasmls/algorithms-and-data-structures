#include <stdio.h>

void func_b(int n);

void func_a(int n)
{
  if (n <= 0)
    return;

  printf("%d ", n);
  func_b(n - 1);
}

void func_b(int n)
{
  if (n <= 1)
    return;

  printf("%d ", n);
  func_a(n / 2);
}

int main()
{
  func_a(20); // Prints out: 20 19 9 8 4 3 1
}