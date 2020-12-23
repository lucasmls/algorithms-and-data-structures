#include <stdio.h>

#include "../../data-structures/stack/stack.h"

void parenthesis_matching(char expression[])
{
  _stack_t stack = stack_create(16);

  for (int i = 0; expression[i] != '\0'; i++)
  {
    char character = expression[i];

    if (character == '(')
    {
      stack_push(&stack, character);
      continue;
    }

    if (stack_is_empty(&stack) && character == ')')
    {
      printf("The parenthesis is not matching");
      return;
    }

    if (character == ')')
    {
      stack_pop(&stack);
    }
  }

  if (!stack_is_empty(&stack))
  {
    printf("The parenthesis is not matching");
    return;
  }

  printf("The parenthesis are matching!");
}

int main()
{
  parenthesis_matching("(a + b + ((x + y) + (1 + 2)))");
}
