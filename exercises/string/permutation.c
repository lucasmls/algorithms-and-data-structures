#include <stdio.h>

void permutation(char str[], int k)
{
  static int hashmap[10] = {0}; // [0, 0, 0, 0]
  static char res[10]; // [a, b, c, d]

  // When i have iterated over the whole string, print out the anagram.
  if (str[k] == '\0')
  {
    res[k] = '\0';
    printf("%s\n", res);
    return;
  }

  for (int i = 0; str[i] != '\0'; i++) // 1
  {
    if (hashmap[i] == 0)
    {
      res[k] = str[i];
      hashmap[i] = 1;
      permutation(str, k + 1);
      hashmap[i] = 0;
    }
  }
}

int main()
{
  char s[] = "abc";
  permutation(s, 0);
}