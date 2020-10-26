#include <stdio.h>

/**
 * Given a string, change its case.
 * Example
 *  input: aBcDeF
 *  output: AbCdEf
 */
void change_case(char str[])
{
  for(int i = 0; str[i] != '\0'; i++)
  {
    int letter_unicode = str[i];
    if (letter_unicode >= 97 && letter_unicode <= 122)
    {
      str[i] = str[i] - 32;
      continue;
    }

    if (letter_unicode >= 65 && letter_unicode <= 90)
      str[i] = str[i] + 32;
  }
}

int main()
{
  char lucas[] = "lUcás";
  change_case(lucas);

  printf("\n%s", lucas);
}
