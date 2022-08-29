# Chapter 1 Notes


## 1.2 Variables and Arithmetic Expressions

#### Data Types
```C
char int float short long double
```
Size of these objects are machine-dependent (Architecture, is it 32-bit, 64-bit, or otherwise)

sidenote: these types can be used with: `arrays, structures, unions, pointers, and functions`

#### Floating-points with printf
Width: The # of characters of width to print to console
Precision: # of decimals to add

ex:
```C
%6.2f // prints 6 wide with 2 decimal points
```

in the case where the number is not 6 digits wide, the characters
will be displayed as empty whitespace

printf available formatting directives:

```C
%d // decimal
%f // floating point
%o // octal
%x // hexadecial
%c // char
%s // char string
%% // for %
```

Excercise 1-3: mod temp conversion to print a heading above the table
Exercise 1-4: write a program to print Celsius -> Fahrenheit conversion

## 1.3 The for statement

Syntax

```C
for ( i = 0; i < whatever; i++) {
  // ... logic
}

AKA

for ( initialization; breaking condition; increment step) {
  // ... logic
}
```

Exercise 1-5: Modify the temperature conversion program to print the table in reverse order, that is, from 300 degrees to 0.

## 1.4 Symbolic Constants
sidenote: It's bad practice to use magic numbers, aka, number literals that have no context. instead, use a symbolic constant:

Syntax:
```C
#define name replacement text
```
any occurence of `name` gets replaced by the corresponding `replacement text`

ex:
```C
#include <stdio.h>

#define LOWER 0       /** lower lim of table */
#define UPPER 300     /** upper lim */
#define STEP 20       /** step size */

/* Print fahrenheit-celsius table */
main() {
  int fahr;
  
  for (fahr = LOWER; fahr <= UPPER; fahr = fahr += STEP)
    printf("%3d %6.1f\n", fahr, (5.0/9.0) * (fahr - 32));
}
```

## 1.5 Character Input Output
Text Input Output is dealt with as streams of characters.
a _text stream_ is a sequence of chars divided into lines, followed by a newline (\\n) character

C standard lib offers `getchar` and `putchar` methods among others.

```C
c = getchar(); // c contains the next character of input
putchar(c); // prints a character each time it's called
```

output will appear in the order in which calls are made

#### 1.5.1 File Copying

pseudo code for file copying:
```
read a character
  while(character !== end-of-file indicator) {
    output the character just read
    read a character
  }
```

pay attention to how `file-copy.c` uses `getchar` and `putchar` as well as how the code is refactored in `file-copy2.c`

`!=` has a higher precedence than `=`, so:
```C
c = getchar() != EOF;
// Equals
c = (getchar() != EOF);
// making `=` take precedence with parenthesis
(c = getchar()) != EOF;
```

Exercise 1-6: Verify that the expression getchar() != EOF is 0 or 1.
Exercise 1-7: Write a program to print the value of EOF.
