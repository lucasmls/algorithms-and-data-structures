#include <stdio.h>

#include "../../data-structures/stack/stack.h"

/**
 * @brief Checks if the given symbol is a opening bracket. (, {, [
 */
int is_opening_brackets(int bracket)
{
  int parenthesis = 40;
  int square_brackets = 91;
  int curly_braces = 123;

  return (
      bracket == parenthesis ||
      bracket == square_brackets ||
      bracket == curly_braces);
}

/**
 * @brief Checks if the given symbol is a closing bracket. ), }, ]
 */
int is_closing_brackets(int bracket)
{
  int parenthesis = 41;
  int square_brackets = 93;
  int curly_braces = 125;

  return (
      bracket == parenthesis ||
      bracket == square_brackets ||
      bracket == curly_braces);
}

/**
 * @brief Checks if the given brackets (opening and closing) are are matching. For example: (), {}, []
 */
int is_brackets_matching(int opening_bracket, int closing_bracket)
{
  int opening_parenthesis = 40;
  int opening_square_brackets = 91;
  int opening_curly_braces = 123;

  int closing_parenthesis = 41;
  int closing_square_brackets = 93;
  int closing_curly_braces = 125;

  if (opening_bracket == opening_parenthesis && closing_bracket == closing_parenthesis)
    return 1;

  if (opening_bracket == opening_square_brackets && closing_bracket == closing_square_brackets)
    return 1;

  if (opening_bracket == opening_curly_braces && closing_bracket == closing_curly_braces)
    return 1;

  return 0;
}

void balanced_expression(char expression[])
{
  _stack_t stack = stack_create(64);

  for (int i = 0; expression[i]; i++)
  {
    int symbol = expression[i];

    if (is_opening_brackets(symbol))
    {
      stack_push(&stack, symbol);
      continue;
    }

    if (stack_is_empty(&stack) && is_closing_brackets(symbol))
    {
      printf("The expression are not balanced!\n");
      return;
    }

    if (is_closing_brackets(symbol))
    {
      if (!is_brackets_matching(stack_peek(&stack), symbol))
      {
        printf("The expression are not balanced!\n");
        return;
      }

      stack_pop(&stack);
    }
  }

  if (!stack_is_empty(&stack))
  {
    printf("The expression are not balanced!\n");
    return;
  }

  printf("The expression are balanced!\n");
}

int main()
{
  balanced_expression("([a + b] + {1 + 2} - ((x + y) + (1 + 2)))");
  balanced_expression("([a + b] + {1 + 2]]]]] - ((x + y) + (1 + 2)))");
}
