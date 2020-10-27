#include <stdio.h>

#include "../../data-structures/array/array.h"

/**
 * Given a lowercase string.
 * Prints out the letters that appears more than once and the quantity.
 */
void duplicates(char chars[])
{
  array_t chars_hash = array_create(26);
  for (int i = 0; i < chars_hash.capacity; i++)
  {
    array_push(&chars_hash, 0);
  }

  for (int i = 0; chars[i] != '\0'; i++)
  {
    int letter_unicode = chars[i];
    int index = letter_unicode - 97;

    chars_hash.items[index]++;
  }

  for (int i = 0; chars[i] != '\0'; i++)
  {
    int letter_unicode = chars[i];
    int index = letter_unicode - 97;

    if (array_get(&chars_hash, index) > 1)
    {
      printf("%c appeared %d times\n", chars[i], array_get(&chars_hash, index));
      array_set(&chars_hash, index, 0);
    }
  }
}

int main()
{
  char letters[] = "laisla";
  duplicates(letters);
}