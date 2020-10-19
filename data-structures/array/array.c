#include <stdio.h>
#include <stdlib.h>

#include "array.h"

/**
 * Creates an array.
 */
array_t array_create(int capacity)
{
  array_t arr;

  arr.capacity = capacity;
  arr.length = 0;
  arr.items = malloc(capacity * sizeof(array_element));

  return arr;
}

/**
 * Destroys the array.
 */
void array_destroy(array_t *arr)
{
  free(arr->items);
  arr = NULL;
}
/**
 * Access a element in a specific index.
 */
array_element array_get(array_t *arr, int index)
{
  if (index < 0 || index >= arr->length)
  {
    fprintf(stderr, "@array_get: Index out of range.");
    exit(1);
  }

  return arr->items[index];
}

/**
 * Sets a new element into a specific index.
 */
void array_set(array_t *arr, int index, array_element element)
{
  if (index < 0 || index >= arr->length)
  {
    fprintf(stderr, "@array_set: Index out of range.");
    exit(1);
  }

  arr->items[index] = element;
}

/**
 * Pushes a new element into the array.
 */
void array_push(array_t *arr, array_element element)
{
  if (array_is_full(arr))
  {
    fprintf(stderr, "@array_append: The array is full.");
    exit(1);
  }

  arr->items[arr->length++] = element;
}

/**
 * Inserts a new element into a specific index of the array.
 */
void array_insert(array_t *arr, int index, array_element element)
{
  if (index < 0 || index >= arr->length)
  {
    fprintf(stderr, "@array_insert: Index out of range.");
    exit(1);
  }

  for (int i = arr->length; i > index; i--)
  {
    arr->items[i] = arr->items[i - 1];
  }

  arr->length++;
  arr->items[index] = element;
}

/**
 * Removes a element from a specific index of the array.
 */
array_element array_remove(array_t *arr, int index)
{
  if (index < 0 || index >= arr->length)
  {
    fprintf(stderr, "@array_remove: Index out of range.");
    exit(1);
  }

  array_element removed_element = arr->items[index];

  for (int i = index; i < arr->length - 1; i++)
  {
    arr->items[i] = arr->items[i + 1];
  }

  arr->length--;

  return removed_element;
};

/**
 * Reverts the position of the elements.
 */
void array_reverse(array_t *arr)
{
  array_element temp;

  for (int left = 0, right = (arr->length - 1); left < right; left++, right--)
  {
    temp = arr->items[left];

    arr->items[left] = arr->items[right];
    arr->items[right] = temp;
  }
};

/**
 * Returns the element with the maximum value.
 */
array_element array_max(array_t *arr)
{
  array_element max = arr->items[0];

  for (int i = 1; i < arr->length; i++)
  {
    if (arr->items[i] > max)
    {
      max = arr->items[i];
    }
  }

  return max;
};

/**
 * Returns the element with the minimum value.
 */
array_element array_min(array_t *arr)
{
  array_element min = arr->items[0];

  for (int i = 1; i < arr->length; i++)
  {
    if (arr->items[i] < min)
    {
      min = arr->items[i];
    }
  }

  return min;
};

/**
 * Returns the sum of all elements of the array.
 */
int array_sum(array_t *arr)
{
  int total = 0;

  for (int i = 0; i < arr->length; i++)
  {
    total += arr->items[i];
  }

  return total;
};

/**
 * Returns the average value of all elements of the array.
 */
float array_avg(array_t *arr)
{
  return (float)array_sum(arr) / arr->length;
};

/**
 * Returns a boolean showing if the array is full or not.
 */
int array_is_full(array_t *arr)
{
  return arr->length == arr->capacity;
}

/**
 * Returns a boolean showing if the array is empty or not.
 */
int array_is_empty(array_t *arr)
{
  return arr->length == 0;
}

/**
 * Informs if the given array is sorted or not.
 */
int array_is_sorted(array_t *arr)
{
  for (int i = 0; i < arr->length - 1; i++)
  {
    if (arr->items[i] > arr->items[i + 1])
    {
      return -1;
    }
  }

  return 1;
}

/**
 * Splits the array between negative values in the left side and positive values in the right side
 * Example:
 *  input:  [4, 6, 8, -10, 12, 14, -2, 16, -18, 20]
 *  output: [-18, -2, -10, 8, 12, 14, 6, 16, 4, 20]
 */
void array_split_between_negatives(array_t *arr)
{
  int i = 0;
  int j = arr->length - 1;

  while (j >= i)
  {
    while (arr->items[i] < 0)
    {
      i++;
    }

    while (arr->items[j] >= 0)
    {
      j--;
    }

    if (i < j)
    {
      array_element temp = arr->items[i];

      arr->items[i] = arr->items[j];
      arr->items[j] = temp;
    }
  }
}

/**
 * Given two sorted arrays, merge them sorted.
 */
array_t array_merge(array_t *first_array, array_t *second_array)
{
  array_t merged_array = array_create(first_array->length + second_array->length);

  int i = 0;
  int j = 0;

  while (i < first_array->length && j < second_array->length)
  {
    if (array_get(first_array, i) < array_get(second_array, j))
    {
      array_push(&merged_array, array_get(first_array, i));
      i++;
      continue;
    }

    array_push(&merged_array, array_get(second_array, j));
    j++;
  }


  for(; i < first_array->length; i++)
  {
    array_push(&merged_array, array_get(first_array, i));
  }

  for(; j < second_array->length; j++)
  {
    array_push(&merged_array, array_get(second_array, j));
  }

  return merged_array;
}

/**
 * Prints out all the items of the array.
 */
void array_print(array_t *arr)
{
  for (int i = 0; i < arr->length; i++)
  {
    printf("%d ", arr->items[i]);
  }

  printf("\n");
};
