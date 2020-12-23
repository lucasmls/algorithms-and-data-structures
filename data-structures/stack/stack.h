#ifndef STACK_H
#define STACK_H

/**
 * @brief Stack is a linear data structure which follows a particular order in which the operations are performed.
 *        The order may be LIFO (Last In First Out) or FILO (First In Last Out)
 * @param capacity is the total capacity of items that the Stack can hold
 * @param top is the index of the top most item in the Stack
 * @param data is the array that holds the Stack items
 */
typedef struct Stack
{
  int capacity;
  int top;
  int *data;
} _stack_t;

/**
 * @brief Creates a new Stack
 */
_stack_t stack_create(int capacity);

/**
 * @brief Inserts a new item into the Stack
 */
void stack_push(_stack_t *stack, char item);

/**
 * @brief Remove and returns the top most item of the Stack
 */
char stack_pop(_stack_t *stack);

/**
 * @brief Take a peek in to the top most item of the Stack
 */
char stack_peek(_stack_t *stack);

/**
 * @brief Returns how much items is stored in the Stack.
 */
int stack_size(_stack_t *stack);

/**
 * @brief Checks if the Stack is full in its capacity
 */
int stack_is_full(_stack_t *stack);

/**
 * @brief Checks if the Stack is empty in its capacity
 */
int stack_is_empty(_stack_t *stack);

#endif
