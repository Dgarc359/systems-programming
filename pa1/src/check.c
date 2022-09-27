#include "balance.h"
#define BUFSIZE 400

int isNotClosingSymbol(char symbol) {
  for (int i = 0; closing_symbols[i] != '\0'; i++) {
    char check_symbol = closing_symbols[i];
    if (check_symbol == symbol) {
      return 0;
    }
  }
  return 1;
}

int isNotOpeningSymbol(char symbol) {
  for (int i = 0; opening_symbols[i] != '\0'; i++) {
    char check_symbol = opening_symbols[i];
    if (check_symbol == symbol){
      return 0;
    }
  }
  return 1;
}

checkClosingSymbolBalances(char peeked, char check_char) {
    for (int i = 0; opening_symbols[i] != '\0'; i++)
        if (opening_symbols[i] == peeked && closing_symbols[i] == check_char)
            return 1;
        return 0;
}

int check(char str[]) {

  char buf[BUFSIZE];
  char* stack = buf;

  int bufp = 0;
  int* stackPointer = &bufp;

  for(int i = 0; i <= BUFSIZE; i++)
      buf[i] = '\0';
  printf("open: %c close: %c\n", opening_symbols[0], closing_symbols[0]);

  int length = 0;
  char check_char;
  for (int i = 0; str[i] != '\0'; i++)
    length++;
  
  for (int i=0; i <= length ; i++) {
    check_char = str[i];
    printf("inside for loop\ncheck_char: %c\n", str[i]);

    int isNotClosingSymbolReturn = isNotClosingSymbol(check_char);
    int isNotOpeningSymbolReturn = isNotOpeningSymbol(check_char);
    if(isNotClosingSymbolReturn && !isNotOpeningSymbolReturn) { //char is opening symbol
      printf("char is opening symbol\n");
      push(check_char, buf, stackPointer);
      printf("pushed elem");
    } else if (!isNotClosingSymbolReturn && isNotOpeningSymbolReturn) { // char is closing symbol
      printf("char is closing symbol\n");
      char peeked = peek(buf, stackPointer);
      int closingSymbolBalancesOpeningSymbol = checkClosingSymbolBalances(peeked, check_char);
      if (closingSymbolBalancesOpeningSymbol)
        pop(stack, stackPointer);
    } else {
      printf("char is neither\n");
    }
  }

  char peeked = peek(buf, bufp);
  if (peeked == '\0') {
    printf("balanced");
    return 1;
  }


  // returns 1 if input stream contains a balanced string
  // 0 otherwise

  // use most recent list of pairs
  // use a stack to check the balance of opening and closing symbols
  printf("unbalanced");
  return 0;
}

int push(int element, char stack[], int* pointer){
    if (*pointer >= BUFSIZE) {
        printf("stack is at max limit");
        return 1;
    }
    else {
        stack[(*pointer)++] = element;
        return 0;
    }
}

void pop(char stack[], int* pointer) {
    if(*pointer > 0)
        stack[--(*pointer)] = '\0';
}

char peek(char stack[], int* pointer) {
    int i;
    for (i = 0; stack[i] != '\0' ; i++);
    return stack[--i];
}