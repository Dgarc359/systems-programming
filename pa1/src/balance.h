#include <stdio.h>
int check(char str[]);
void pair(char list[]);

extern int opening_symbols[51];
extern int closing_symbols[51];

int *opening_symbols_pointer[51];
opening_symbols_pointer = &opening_symbols;

int *closing_symbols_pointer[51];
closing_symbols_pointer = &closing_symbols;