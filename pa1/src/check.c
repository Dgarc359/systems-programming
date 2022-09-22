#include "balance.h"

int isNotClosingSymbol(int symbol) {
  for (int i = 0; i != NULL; i++)
    if (closing_symbols[i] == symbol) {
      printf("char from closing_symbols: %c\n", closing_symbols[i]);
      printf("char is closing symbol in check fn\n");
      return 0;
    }
  return 1;
}

int isNotOpeningSymbol(int symbol) {
  for (int i = 0; i != NULL; i++) {
    printf('%c\n', opening_symbols[i]);
    if (opening_symbols[i] == symbol){
      printf("char is opening symbol in check fn\n");
      return 0;
    }
  }
  return 1;
}

int check(char str[]) {
  printf("open: %c close: %c\n", opening_symbols[0], closing_symbols[0]);

  int length = 0;
  int check_char;
  getchar();
  // for (int i = 0, check_char = str[i]; check_char != NULL || check_char != EOF; i++){
  for (int i=0; str[i] != '\0'; i++) {
    check_char = str[i];
    printf("inside for loop\ncheck_char: %c\n", str[i]);
    if(isNotClosingSymbol(check_char) && !isNotOpeningSymbol(check_char)) { //char is opening symbol
      printf("char is opening symbol\n");
      push(check_char);
    } else if (!isNotClosingSymbol(check_char) && isNotOpeningSymbol(check_char)) { // char is closing symbol
      printf("char is opening symbol\n");
      int peeked = peek();
      if (peeked == check_char)
        pop();
    } else {
      printf("char is neither");
    }
    getchar();
  }

  if (peek() == NULL) {
    printf("balanced");
    return 1;
  }


  // returns 1 if input stream contains a balanced string
  // 0 otherwise

  // use most recent list of pairs
  // use a stack to check the balance of opening and closing symbols
  printf('unbalanced');
  return 0;
}