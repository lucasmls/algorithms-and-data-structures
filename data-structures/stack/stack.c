#include <stdio.h>
#include <stdlib.h>

#include "stack.h"

/**
 * @brief Creates a new Stack
 */
_stack_t stack_create(int capacity)
{
  _stack_t stack;

  stack.capacity = capacity;
  stack.data = malloc(capacity * sizeof(int));
  stack.top = -1;

  return stack;
};

/**
 * @brief Inserts a new item into the Stack
 */
void stack_push(_stack_t *stack, int item)
{
  if (stack_is_full(stack))
  {
    fprintf(stderr, "@stack_push: The Stack is full.");
    exit(1);
  };

  stack->top++;
  stack->data[stack->top] = item;
}

/**
 * @brief Remove and returns the top most item of the Stack
 */
int stack_pop(_stack_t *stack)
{
  if (stack_is_empty(stack))
  {
    fprintf(stderr, "@stack_pop: The Stack is empty.");
    exit(1);
  }

  int item = stack->data[stack->top];
  stack->top--;

  return item; 
};

/**
 * @brief Take a peek in to the top most item of the Stack
 */
int stack_peek(_stack_t *stack)
{
  if (stack_is_empty(stack))
  {
    fprintf(stderr, "@stack_peek: The Stack is empty.");
    exit(1);
  }

  return stack->data[stack->top];
};

/**
 * @brief Returns how much items is stored in the Stack.
 */
int stack_size(_stack_t *stack)
{
  return stack->top + 1;
};

/**
 * @brief Checks if the Stack is full in its capacity
 */
int stack_is_full(_stack_t *stack)
{
  return (stack->capacity - 1) == stack->top;
};

/**
 * @brief Checks if the Stack is empty in its capacity
 */
int stack_is_empty(_stack_t *stack)
{
  return stack->top == -1;
};
