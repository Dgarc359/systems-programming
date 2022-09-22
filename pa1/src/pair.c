#include "balance.h"
int opening_symbols[51];
int closing_symbols[51];

void flush(){
  for (int i = 0; i < 52; i++) {
    opening_symbols[i] = NULL;
    closing_symbols[i] = NULL;
  }
}

void pair(char list[])
{
  printf("test: %s\n", list);
  int opening_symbols_counter = 0;
  int closing_symbols_counter = 0;

  flush();

  for (int i = 0; i < 401 && list[i] != '\0'; i++)
  { // 400 is our max string size
    if (list[i] == ' ' || list[i] == '\n' || list[i] == '\t')
    {
      continue;
    }
    else if (list[i] == ',')
    {
      // this means the next value will be our closing symbol
      // take the next value and increase i so that it increases by two and skips
      int opening = list[i-1];
      int closing = list[i+1];

      if(
        opening == ' ' || opening == '\n' || opening == '\t' || opening == ',' ||
        closing == ' ' || closing == '\n' || closing == '\t' || closing == ','
      ) {
        printf("You screwed up! Please input the correct chars");
        flush();
        return;
      }
      else {
        opening_symbols[opening_symbols_counter++] = opening;
        closing_symbols[closing_symbols_counter++] = closing;
      }
    }
    if (i == 400) {
      opening_symbols[opening_symbols_counter] = NULL;
    }
  }

  for (int i = 0; i < 52 && opening_symbols[i] != NULL && closing_symbols[i] != NULL; i++)
  {
    printf("opening symbol: %c\n", opening_symbols[i]);
    printf("closing symbols: %c\n", closing_symbols[i]);
  }
}