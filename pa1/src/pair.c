#include "balance.h"
int opening_symbols[51];
int closing_symbols[51];

void pair(char list[])
{
  // printf("test\n");
  printf("test: %s\n", list);
  int opening_symbols_counter = 0;
  for (int i = 0; i < 401 && list[i] != '\0'; i++)
  { // 400 is our max string size
    // printf("%i: char %c\n", i, list[i]);
    if (list[i] == ' ')
    {
      // Go to the next iteration
      continue;
    }
    else if (list[i] == ',')
    {
      // this means the next value will be our closing symbol
      // take the next value and increase i so that it increases by two and skips
      i++;
    }
    else
    {
      // opening symbol, put it opening symbol array
      opening_symbols[opening_symbols_counter] = list[i];
      opening_symbols_counter++;
    }
    if (i == 400) {
      opening_symbols[opening_symbols_counter] = NULL;
    }
  }

  for (int i = 0; i < 52 && opening_symbols[i] != NULL; i++)
  {
    printf("opening symbol: %i\n", opening_symbols[i]);
  }
  // gets list of opening and closing symbols

  // stores opening / closing in arrays
}