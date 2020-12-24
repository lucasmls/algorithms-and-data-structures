#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stddef.h>
#include "../../data-structures/stack/stack.h"

/**
 * @brief Checks if the given symbol is a valid operator. (+), (-), (*), (/)
 */
int is_operator(int operator)
{
  int sum = 43;
  int subtraction = 45;
  int multiplication = 42;
  int division = 47;

  return (
      operator== sum ||
      operator== subtraction ||
      operator== multiplication ||
      operator== division);
}

/**
 * @brief Checks if the given symbol is a valid operand. (0~9)
 */
int is_operand(int operand)
{
  return operand > 47 && operand < 58;
}

/**
 * @brief Returns the priority of the given operator. (+), (-), (*), (/)
 */
int priority(int operator)
{
  switch (operator)
  {
  case '(':
    return 0;

  case '+':
  case '-':
    return 1;

  case '*':
  case '/':
    return 2;
  }

  return -1;
}

/**
 * @brief Converts a expression in infix format to postfix format.
 */
char *infix2postfix(char *expression)
{
  _stack_t stack = stack_create(strlen(expression));

  char *postfix = malloc(strlen(expression) * sizeof(char));
  int postfix_size = 0;

  for (int i = 0; expression[i]; i++)
  {
    int symbol = expression[i];

    if (is_operand(symbol))
    {
      postfix[postfix_size++] = expression[i];
    }
    else if (is_operator(symbol))
    {
      while (!stack_is_empty(&stack) && priority(stack_peek(&stack)) >= priority(expression[i]))
      {
        postfix[postfix_size++] = stack_pop(&stack);
      }

      stack_push(&stack, expression[i]);
    }
    else if (symbol == '(')
    {
      stack_push(&stack, symbol);
    }
    else if (symbol == ')')
    {
      while (stack_peek(&stack) != '(')
      {
        postfix[postfix_size++] = stack_pop(&stack);
      }

      stack_pop(&stack);
    }
  }

  while (!stack_is_empty(&stack))
  {
    postfix[postfix_size++] = stack_pop(&stack);
  }

  postfix[postfix_size] = '\0';

  return postfix;
}

int main()
{
  printf("%s\n", infix2postfix("((2*6)+(1/4))"));
  printf("%s\n", infix2postfix("2+6*4-9"));
  printf("%s\n", infix2postfix("(2+8)*9"));
  printf("%s\n", infix2postfix("(2 + 9)*12+(5/1)"));
}
