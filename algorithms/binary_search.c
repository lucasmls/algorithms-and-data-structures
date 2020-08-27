#include <stdio.h>

/**
 * Search a sorted array by repeatedly dividing the search interval in half.
 * Begin with an interval covering the whole array. If the value of the search key is less
 * than the item in the middle of the interval,  narrow the interval to the lower half.
 * Otherwise narrow it to the upper half. Repeatedly check until the value is found or the interval is empty.
 *
 * Time complexity: O(Log n)
 */

int binary_search(int arr[], int element, int size) {
  int left = 0;
  int right = size -1;

  while (left <= right) {
    int middle = (left + right) / 2;
    int guess = arr[middle];

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
  int items[] = {2, 4, 6, 8, 10, 12, 14, 16, 18, 20};
  int size = sizeof(items) / sizeof(items[0]);

  int pos = binary_search(items, 12, size);
  printf("Position of number 12: %d\n", pos);

  pos = binary_search(items, 20, size);
  printf("Position of number 20: %d\n", pos);

  pos = binary_search(items, 0, size);
  printf("Position of number 0: %d\n", pos);
}