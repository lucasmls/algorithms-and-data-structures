#include <stdio.h>

#include "../../data-structures/array/array.h"

/**
 * Given a list of sorted numbers that goes from N-N
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

/**
 * Given a list of unsorted numbers that goes from N-N
 * Find the missing number in between the list.
 */
void multiple_missing_number_unsorted_N_N(array_t arr)
{
  int min = array_min(&arr);
  int max = array_max(&arr);

  array_t hash = array_create(max - min);
  for (int i = 0; i < hash.length; i++)
  {
    array_push(&hash, 0);
  }

  for (int i = 0; i < arr.length; i++)
  {
    hash.items[arr.items[i] - min]++;
  }

  for (int i = 1; i <= arr.length; i++)
  {
    if (hash.items[i] == 0)
    {
      printf("Missing: %d\n", i + min);
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

  multiple_missing_number_unsorted_N_N(n_to_n);
}