#include <stdio.h>

#include "../data-structures/array/array.h"

/**
 * The selection sort algorithm sorts an array by repeatedly finding
 * the minimum element (considering ascending order) from unsorted part and
 * putting it at the beginning.
 *
 * Time Complexity: O(n^2)
 * https://www.geeksforgeeks.org/selection-sort/
 */

void selection_sort(array_t *arr)
{
  int i, j, min, temp;

  for (i = 0; i < arr->length; i++)
  {
    min = i;

    for (j = i + 1; j < arr->length; j++)
    {
      if (array_get(arr, j) < array_get(arr, min))
      {
        min = j;
      }
    }

    temp = array_get(arr, i);

    array_set(arr, i, array_get(arr, min));
    array_set(arr, min, temp);
  }
}

int main()
{
  array_t arr = array_create(8);

  array_push(&arr, 20);
  array_push(&arr, 17);
  array_push(&arr, 10);
  array_push(&arr, 18);
  array_push(&arr, 4);
  array_push(&arr, 3);
  array_push(&arr, 21);
  array_push(&arr, 13);

  printf("Unsorted array: \n");
  array_print(&arr);

  selection_sort(&arr);

  printf("Sorted array: \n");
  array_print(&arr);
}