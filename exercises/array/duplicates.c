#include <stdio.h>

#include "../../data-structures/array/array.h"

/**
 * Given a list of sorted numbers that goes from N-N
 * Find the duplicate numbers in between the list.
 */
void duplicates(array_t arr)
{
  for (int i = 0; i < arr.length - 1; i++)
  {
    if (array_get(&arr, i + 1) == array_get(&arr, i))
    {
      int j = i + 1;
      while (array_get(&arr, j) == array_get(&arr, i))
      {
        j++;
      }

      printf("%d appeared %d times\n", array_get(&arr, i), j - i);
      i = j - 1;
    }
  }
}

int main()
{
  array_t items = array_create(13);
  array_push(&items, 0);
  array_push(&items, 1);
  array_push(&items, 8);
  array_push(&items, 9);
  array_push(&items, 9);
  array_push(&items, 13);
  array_push(&items, 14);
  array_push(&items, 15);
  array_push(&items, 16);
  array_push(&items, 16);
  array_push(&items, 16);
  array_push(&items, 16);
  array_push(&items, 17);

  duplicates(items);
}