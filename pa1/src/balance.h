#include <stdio.h>
int check(char str[]);
void pair(char list[]);

extern char opening_symbols[52];
extern char closing_symbols[52];

int push(int element, char stack[], int* pointer);
void pop(char stack[], int* pointer);
char peek(char stack[], int* pointer);

// int *opening_symbols_pointer[51];
// opening_symbols_pointer = &opening_symbols;

// int *closing_symbols_pointer[51];
// closing_symbols_pointer = &closing_symbols;