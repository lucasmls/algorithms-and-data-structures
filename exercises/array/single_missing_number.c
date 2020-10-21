#include <stdio.h>
#include "../../data-structures/array/array.h"

/**
 * Given a list of sorted numbers starting from 1-N
 * Find the missing number in between the list.
 */
int find_single_missing_number_1_N(array_t arr)
{
  int sum = array_sum(&arr);
  // arr.length +1 because the array size would be 11, but with one missing number
  // so, the correct list size should be 12.
  int n = (arr.length + 1) * (arr.length + 2) / 2;

  return sum - n;
}

/**
 * Given a list of sorted numbers that goes from N-N
 * Find the missing number in between the list.
 */
int find_single_missing_number_N_N(array_t arr)
{
  int min = array_min(&arr);
  int diff = min - 0;

  for (int i = 0; i < arr.length; i++)
  {
    if (arr.items[i] - i != diff)
    {
      return diff + i;
    }
  }

  return -1;
}

/**
 * Given a list of unsorted numbers that goes from N-N
 * Using brute force, find the missing number in between the list.
 */
int bf_find_single_missing_number_in_unsorted(array_t arr)
{
  int min = array_min(&arr);

  for (int i = 0; i < arr.length; i++)
  {
    int position = array_index_of(&arr, min + i);
    if (position == -1)
    {
      return min + i;
    }
  }

  return -1;
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

  int missing_number = find_single_missing_number_1_N(items);
  printf("The missing number is: %d\n", missing_number);

  array_t n_to_n = array_create(11);
  array_push(&n_to_n, 6);  // index: 0
  array_push(&n_to_n, 7);  // index: 1
  array_push(&n_to_n, 8);  // index: 2
  array_push(&n_to_n, 9);  // index: 3
  array_push(&n_to_n, 10); // index: 4
  array_push(&n_to_n, 11); // index: 5
  array_push(&n_to_n, 13); // index: 6
  array_push(&n_to_n, 14); // index: 7
  array_push(&n_to_n, 15); // index: 8
  array_push(&n_to_n, 16); // index: 9
  array_push(&n_to_n, 17); // index: 10

  missing_number = find_single_missing_number_N_N(n_to_n);
  printf("The missing number is: %d\n", missing_number);

  array_t unsorted_n_to_n = array_create(11);
  array_push(&unsorted_n_to_n, 6);  // index: 0
  array_push(&unsorted_n_to_n, 16); // index: 1
  array_push(&unsorted_n_to_n, 7);  // index: 2
  array_push(&unsorted_n_to_n, 17); // index: 3
  array_push(&unsorted_n_to_n, 10); // index: 4
  array_push(&unsorted_n_to_n, 8);  // index: 5
  array_push(&unsorted_n_to_n, 11); // index: 6
  array_push(&unsorted_n_to_n, 13); // index: 7
  array_push(&unsorted_n_to_n, 14); // index: 8
  array_push(&unsorted_n_to_n, 9);  // index: 9
  array_push(&unsorted_n_to_n, 15); // index: 10

  missing_number = bf_find_single_missing_number_in_unsorted(unsorted_n_to_n);
  printf("The missing number of the unsorted array is: %d\n", missing_number);
}