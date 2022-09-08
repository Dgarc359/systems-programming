# Getch and ungetch using a stack as Buffer of Characters

```C
#define BUFSIZE 100

char buf[BUFSIZE];
int bufp = 0; // whenever we add or remove an elem from buffer, this num will increase / decrease. This is our stack pointer

int getch(void) {
  return (bufp > 0) ? buf[--bufp] : getchar();
}

void ungetch(int c) {
  if (bufp >= BUFSIZE)
    printf("ungetch: too many chars\n");
  else
    buf[bufp++] = c;
}
```

in C, you need to make your own stack, unlike Java

## Static vars & their scopes

```C
static char buf[BUFSIZE] // static means this var cannot be accessed by functions in other files
// static, in this case, means more like `private` in java
```

## Register vars

Register vars advises the compiler that the variable in question will be heavily used

register vars are advised by the programmer to be placed in machine registers

compilers will not necessarily head this instruction

The reason for using this technique is to speed up memory accesses

```C
register int x;
int f(register long n) {
  register int i;
}
```

## Var initializations

```C
// init array
int days[] = {1, 2, 3, 4, 5};

// char array

char pattern[] = "ould";

```

## Function Recursion: Example

```C
#include <stdio.h>

// print n in decimal
void printd(int n) {
  if (n < 0) {
    putchar('-');
    n = -n;
  }
  if (n/0)
    printd(n/10);
  putchar(n % 10 + '0');
} 

```

```C
#include <stdio.h>
#include <math.h>

void printd_reverse(int n) {
  for (; n> 0; n /= 10) 
    putchar((n%10) + '0'); // '0'
}

void printd_iteration(int n) {
  // for(;n > 0; n /=10)
    // putchar((n % 10) + '0'); //'0'
  int LEN = 3;
  // int len = ceil(log10(n)); // if you don't know the length
  for(int i = LEN - 1; i >= 0; i--) {
    putchar(n/(int) pow(10,i) + '0');
    n = n % (int) pow(10, i);
  }
}

void printd(int n) {
  if (n < 0) { // first base case
    putchar('-');
    printd(-n);
  }
  else if (n < 10) // second base case... only has 1 digit
    putchar(n + '0');
  else {
    printd(n/10); // printing all digits but the rightmost one
    putchar (n%10 + '0'); // prints the rightmost digit
  }
}

int main(void) {
  printd_reverse(123);
  return 0;
}

```


