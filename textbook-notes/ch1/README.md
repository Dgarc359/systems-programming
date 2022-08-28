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