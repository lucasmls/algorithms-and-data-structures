#include <stdio.h>

int nested(int n)
{
  if (n > 100)
    return n - 10;

  return nested(nested(n + 11));
}

int main()
{
  printf("%d\n", nested(95)); // 91
}