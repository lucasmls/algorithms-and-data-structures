#include <stdio.h>

int using_static_variable(int n)
{
  static int x = 0;

  if (n <= 0)
  {
    return 0;
  }

  x++;
  return using_static_variable(n - 1) + x;
}

int global_x = 0;
int using_global_variable(int n)
{
  if (n <= 0)
  {
    return 0;
  }

  global_x++;
  return using_global_variable(n - 1) + global_x;
}

int main()
{
  int r = using_static_variable(5);
  printf("Result using static variable: %d\n", r);

  r = using_static_variable(5);
  printf("Result using static variable: %d\n", r);

  int rg = using_global_variable(5);
  printf("Result using global variable: %d\n", rg);

  rg = using_global_variable(5);
  printf("Result using global variable: %d\n", rg);
}