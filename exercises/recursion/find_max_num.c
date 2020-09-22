#include <stdio.h>

#include "../../data-structures/array/array.h"

int find_max(array_t arr)
{
  array_element head = array_get(&arr, 0);

  if (arr.length == 1)
    return head;

  if (arr.length == 2)
  {
    if (head > array_get(&arr, 1))
    {
      return head;
    }

    return array_get(&arr, 1);
  }

  array_remove(&arr, 0);
  int sub_max = find_max(arr);

  if (head > sub_max)
    return head;

  return sub_max;
}

int main()
{
  array_t items = array_create(10);
  array_push(&items, 120);
  array_push(&items, 4); 
  array_push(&items, 20);
  array_push(&items, 2); 
  array_push(&items, 8); 
  array_push(&items, 16);
  array_push(&items, 10);
  array_push(&items, 6); 
  array_push(&items, 12);
  array_push(&items, 18);

  int max = find_max(items);
  printf("The maximum number in the arry is: %d\n", max);
}
