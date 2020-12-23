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

/**
 * Given a list of unsorted numbers that goes from N-N
 * Find the missing number in between the list.
 */
void duplicates_hash(array_t arr)
{
  int max = array_max(&arr);

  array_t hash = array_create(max); // 8
  for (int i = 0; i < hash.capacity; i++)
  {
    array_push(&hash, 0);
  }

  for (int i = 0; i < arr.length; i++)
  {
    hash.items[arr.items[i]]++;
  }

  for (int i = 0; i < hash.length; i++)
  {
    if (hash.items[i] > 1)
    {
      printf("%d appeared %d times\n", i, hash.items[i]);
    }
  }
}

int main()
{
  array_t items = array_create(15); // 0 - 7
  array_push(&items, 3);
  array_push(&items, 3);
  array_push(&items, 3);
  array_push(&items, 3);
  array_push(&items, 3);
  array_push(&items, 4);
  array_push(&items, 5);
  array_push(&items, 6);
  array_push(&items, 6);
  array_push(&items, 6);
  array_push(&items, 7);
  array_push(&items, 8);

  duplicates(items);
  printf("-----\n");
  duplicates_hash(items);
}
