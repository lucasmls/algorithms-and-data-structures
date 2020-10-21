#include <stdio.h>

#include "../../data-structures/array/array.h"

/**
 * Given a list of numbers that goes from N-N
 * Find the missing number in between the list.
 */
void multiple_missing_number_N_N(array_t arr)
{
  int min = array_min(&arr);
  int diff = min - 0;

  for (int i = 0; i < arr.length; i++)
  {
    if (array_get(&arr, i) - i != diff)
    {
      for (int j = diff + i; j < array_get(&arr, i); j++)
      {
        printf("Missing: %d\n", diff + i);
        diff++;
      }

      // while(diff + i < array_get(&arr, i))
      // {
      //   printf("Missing: %d\n", diff + i);
      //   diff++;
      // }
    }
  }
}

int main()
{
  array_t n_to_n = array_create(11);
  array_push(&n_to_n, 6);
  array_push(&n_to_n, 7);
  array_push(&n_to_n, 8);
  array_push(&n_to_n, 9);
  array_push(&n_to_n, 13);
  array_push(&n_to_n, 14);
  array_push(&n_to_n, 15);
  array_push(&n_to_n, 16);
  array_push(&n_to_n, 17);

  multiple_missing_number_N_N(n_to_n);
}