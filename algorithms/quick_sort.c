#include <stdio.h>

#include "../data-structures/array/array.h"

/**
 * QuickSort is a Divide and Conquer algorithm.
 * It picks an element as pivot and partitions the given array around the picked pivot.
 * The key process in quickSort is sort_pivot().
 * Given an array and an element x of the array as a pivot, put x at its correct position
 * in sorted array and put all smaller elements (smaller than x) before x, and put all
 * greater elements (greater than x) after x. All this should be done in linear time.
 */

void swap(array_t *arr, int from, int to)
{
  int a = array_get(arr, from);
  int b = array_get(arr, to);

  array_set(arr, to, a);
  array_set(arr, from, b);
}

int sort_pivot(array_t *arr, int start, int end)
{
  int pivot = array_get(arr, end - 1);
  int lowest_than_pivot = 0;

  for (int i = start; i < end -1 ; i++)
  {
    if (array_get(arr, i) <= pivot)
    {
      swap(arr, i, start + lowest_than_pivot);
      lowest_than_pivot++;
    }
  }

  swap(arr, end - 1,  start + lowest_than_pivot);
  return start + lowest_than_pivot;
}

void quick_sort(array_t *arr, int start, int end)
{
  if ((end - start) > 1)
  {
    int pivot_position = sort_pivot(arr, start, end);

    quick_sort(arr, start, pivot_position);
    quick_sort(arr, pivot_position + 1, end);
  }
}

int main()
{
  array_t items = array_create(7);

  array_push(&items, 27);
  array_push(&items, 8);
  array_push(&items, 7);
  array_push(&items, 20);
  array_push(&items, 30);
  array_push(&items, 43);
  array_push(&items, 11);

  array_print(&items);

  quick_sort(&items, 0, items.length);

  array_print(&items);
}
