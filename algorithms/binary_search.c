#include <stdio.h>

#include "../data-structures/array/array.h"

/**
 * Search a sorted array by repeatedly dividing the search interval in half.
 * Begin with an interval covering the whole array. If the value of the search key is less
 * than the item in the middle of the interval,  narrow the interval to the lower half.
 * Otherwise narrow it to the upper half. Repeatedly check until the value is found or the interval is empty.
 *
 * Time complexity: O(Log n)
 */

int binary_search(array_t arr, array_element element) {
  int left = 0;
  int right = arr.length -1;

  while (left <= right) {
    int middle = (left + right) / 2;
    int guess = array_get(&arr, middle);

    if (guess == element) {
      return middle;
    }

    if (guess > element) {
      right = middle -1;
      continue;
    }

    left = middle +1;
  }

  return -1;
}

int main() {
  array_t items = array_create(10);
  array_push(&items, 2);  // index: 0
  array_push(&items, 4);  // index: 1
  array_push(&items, 6);  // index: 2
  array_push(&items, 8);  // index: 3
  array_push(&items, 10); // index: 4
  array_push(&items, 12); // index: 5
  array_push(&items, 14); // index: 6
  array_push(&items, 16); // index: 7
  array_push(&items, 18); // index: 8
  array_push(&items, 20); // index: 9

  int pos = binary_search(items, 12);
  printf("Position of number 12: %d\n", pos);

  pos = binary_search(items, 20);
  printf("Position of number 20: %d\n", pos);

  pos = binary_search(items, 0);
  printf("Position of number 0: %d\n", pos);
}