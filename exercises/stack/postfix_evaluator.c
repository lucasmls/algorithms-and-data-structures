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
 * @brief Evaluates to operands by a operator. (10 - 5) = 15
 */
int eval(int x, int y, int operator)
{
  char op = (char)operator;

  if (op == '+')
    return x + y;

  if (op == '-')
    return x - y;

  if (op == '*')
    return x * y;

  if (op == '/')
    return x / y;

  return -1;
}

int postfix_eval(const char *expression)
{
  _stack_t stack = stack_create(strlen(expression));

  for (int i = 0; expression[i]; i++)
  {
    if (is_operand(expression[i]))
    {
      stack_push(&stack, expression[i] - '0');
    }
    else if (is_operator(expression[i]))
    {
      int b = stack_pop(&stack);
      int a = stack_pop(&stack);
      stack_push(&stack, eval(a, b, expression[i]));
    }
  }

  // Pops out the last evaluation that were left in the Stack.
  int result = stack_pop(&stack);
  return result;
}

int main()
{
  int r = postfix_eval("35*62/+4-");
  printf("%d\n", r);

  r = postfix_eval("26+9-");
  printf("%d\n", r);

  r = postfix_eval("264*+8-");
  printf("%d\n", r);

  r = postfix_eval("284/+");
  printf("%d\n", r);
}
