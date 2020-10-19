#ifndef ARRAY_H
#define ARRAY_H

typedef int array_element;

/**
 * An array is a collection of items stored at contiguous memory locations.
 * The idea is to store multiple items of the same type together
 */
typedef struct Array
{
  int capacity;
  int length;
  array_element *items;
} array_t;

/**
 * Creates an array.
 */
array_t array_create(int capacity);

/**
 * Destroys the array.
 */
void array_destroy(array_t *arr);

/**
 * Access a element in a specific index.
 */
array_element array_get(array_t *arr, int index);

/**
 * Sets a new element into a specific index.
 */
void array_set(array_t *arr, int index, array_element element);

/**
 * Pushes a new element into the array.
 */
void array_push(array_t *arr, array_element element);

/**
 * Inserts a new element into a specific index of the array.
 */
void array_insert(array_t *arr, int index, array_element element);

/**
 * Removes a element from a specific index of the array.
 */
array_element array_remove(array_t *arr, int index);

/**
 * Reverts the position of the elements.
 */
void array_reverse(array_t *arr);

/**
 * Returns the element with the maximum value.
 */
array_element array_max(array_t *arr);

/**
 * Returns the element with the minimum value.
 */
array_element array_min(array_t *arr);

/**
 * Returns the sum of all elements of the array.
 */
int array_sum(array_t *arr);

/**
 * Returns the average value of all elements of the array.
 */
float array_avg(array_t *arr);

/**
 * Returns a boolean showing if the array is full or not.
 */
int array_is_full(array_t *arr);

/**
 * Returns a boolean showing if the array is empty or not.
 */
int array_is_empty(array_t *arr);

/**
 * Informs if the given array is sorted or not.
 */
int array_is_sorted(array_t *arr);

/**
 * Splits the array between negative values in the left side and positive values in the right side
 * Example:
 *  input: [1, 4, -3, -5, 4, 1]
 *  output: [-3, -5, 1, 4, 4, 1]
 */
void array_split_between_negatives(array_t *arr);

/**
 * Given two sorted arrays, merge them sorted.
 */
array_t array_merge(array_t *first_array, array_t *second_array);

/**
 * Prints out all the items of the array.
 */
void array_print(array_t *arr);

#endif