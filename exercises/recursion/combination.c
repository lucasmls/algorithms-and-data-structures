#include <stdio.h>

int nCr(int n, int r)
{
  if (r == 0 || n == r)
    return 1;

  return nCr(n - 1, r - 1) + nCr(n - 1, r);
}

int main()
{
  int r = nCr(4, 2);
  printf("May be %d combinations in a string of size 4. \n", r);

  r = nCr(6, 2);
  printf("May be %d combinations in a string of size 6. \n", r);
}