# Assignment 1

How do you have arrays available in multiple files?

```C
#include "balance.h" // include in check.c, pair.c, and balance_checker.c

// < > are not needed because balance.h is defined inside the project
```

```C
// check.c
#include "balance.h"
int check(char str[]) {
  // ... code
}
```

```C
// pair.c
void pair(char list[]) {
  // ... code
}
```

```C
// balance_check.c
#include "balance.h"
char opening_symbols[51];
int main () {
  // ... code
}
```

```C
// balance.h

// functions have been declared for the compiler to know they exist
void pair(char list[]); 
int check(char str[]);
extern char opening_symbols[51]; // declaring as external, which means this is coming from another file

#include <math.h>
#define max(a, b) ((a) > (b) ? (a) : (b)) // this is an example macro
```

```C
// Makefile

```

compile with `make` in CLI (command line)

`.o` files are object files, Makefile will make the `balance` executable file

popping from an empty stack means you have more closing pairs than open pairs which would be invalid

```C
void push(char c) {
  if (bufp == BUFFSIZE)
    return;
  buf[bufp++] = c;
}
```
```C
char pop() {
  if(bufp ==0)
    return EOF;
  return buf[--bufp];
}
```

```C
int is_balanced(char input[]) {
  // int len = strlen(input);
  

  
  for(int i = 0; i < len; i++) {
    // if (input[i] = '(');
    //   push('(');
    // else if(pop() == EOF)
    //   return 0;
    if(is_opening_symbol(input[i])) // linear search on all opening symbols, if next char is, then push it
    push(input);
    else(!is_closing_symbol(input[i]))
      continue;
    else {
      char closing_symbol = input[i];
      char opening_symbol = pop();
    }
  }

  return bufp == 0;
}
```

```C
void print_binary(int n) {

}
```

# Pointers
a pointer is a group of memory cells that can hold an address

a pointer to a type is written as * after the data type, example: int* / char* / double*

void* is the type for a generic pointer

unary operator & gives address of an obj
`p = &c` assigns the address of var c to pointer p

unary operator * is the dereferencing operator
- when applied to a pointer, it access the object the pointer points to.

```C
int x = 1, y = 2, z[10];
int *ip;      // ip is a pointer to int

ip = &x;      // ip now points to x
y = *ip;      // y is now 1
*ip = 0;      // x is now 0
ip = &z[0];   // ip now points to z[0]
```

program memory contains the stack

at the bottom of the stack, is `main`
every call to a function creates a new stack frame
a stack frame is created for functions to contain their local variables

| STACK |
| ---- |
| main |
| ~~printf~~ |
| g |
| h |

```C
int x = 1, y = 2, z[10];
int *ip;      // ip is a pointer to int

ip = &x;      // ip now points to x
y = *ip;      // y is now 1
*ip = 0;      // x is now 0
ip = &z[0];   // ip now points to z[0]
```
**The above is broken down in the stack below**

| STACK |
| ---- |
| x = ~~1~~ = 0 | addr: 100
| y = ~~2~~ = 1 | addr: 104 (every int is 4 bytes)
| z[0] | addr: 108
| z[1] | addr: 112
| ... | ... 9 x 4 = 36 + 108 = 144
| z[9] | addr: 144
| ip = ~~100~~ = 108 | addr: 148

subtracting 2 pointers results in different operations

difference of two pointers is the # of elements u can store in the addresses between them

ip++ = ip + 1 (int* + sizeof int)

you cannot add two pointers, you cannot add multiply two pointers, you can only subtract two pointers

ip = &z[5]
ip becomes a subarray of z
