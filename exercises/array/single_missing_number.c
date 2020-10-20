#include <stdio.h>
#include "../../data-structures/array/array.h"

/**
 * Given a list of numbers starting from 1-N
 * Find the missing number in between the list.
 */
int find_single_missing_number(array_t arr)
{
  int sum = array_sum(&arr);
  // arr.length +1 because the array size would be 11, but with one missing number
  // so, the correct list size should be 12.
  int n = (arr.length + 1) * (arr.length + 2) / 2;

  return sum - n;
}

int main()
{
  array_t items = array_create(11);
  array_push(&items, 1);  // index: 0
  array_push(&items, 2);  // index: 1
  array_push(&items, 3);  // index: 2
  array_push(&items, 4);  // index: 3
  array_push(&items, 5);  // index: 4
  array_push(&items, 6);  // index: 5
  array_push(&items, 7);  // index: 6
  array_push(&items, 9);  // index: 7
  array_push(&items, 10); // index: 8
  array_push(&items, 11); // index: 9
  array_push(&items, 12); // index: 10

  int missing_number = find_single_missing_number(items);
  printf("The missing number is: %d\n", missing_number);
}