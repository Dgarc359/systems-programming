# Data types and sizes

### Basic Data Types
* char (1 byte) (signed, unsigned)
* int (4 bytes) (short [2 bytes], long [8 bytes] | signed, unsigned)
* float (4 bytes)
* double (8 bytes) (long [16 bytes])

### Short variables
```C
// year of a date cannot be more than a few thousand, short is a good choice
short year; // -2^15 ... 2^15 - 1 (16 bits)

char temperature; // -128 ... 127
```

unsigned int is good for array indexing as it's not generally necessary to use a negative index

12 even 0
6  even 0
3  odd  1
1  odd  1

### Two's Complement
represent the positive number in binary
flip the bits
add +1 to the binary number
flip any bits where there's a carry over from adding one to the bits

passing negative numbers to unsigned numbers results in overflow

### post-fix (different name) data typing
int constant 1234

long const 423894L
float const 12.43 1.2345e2
single precision
double precision

### Bitwise operations
in C there is no booleans, rather binary numbers can be used instead

```C
&   // bitwise AND
|   // bitwise inclusive OR
^   // bitwise exclusive OR
<<  // left shift
>>  // right shift
~   // one's complement (unary)
```

example:

```C
11 & 19
11 // in binary 01011
19 // in binary 10011
// ------------------
//              00011
```

| AND | 0 | 1 |
| --- | --- | --- |
| 0 | 0 | 0 |
|1 | 0 | 1 |


| OR | 0 | 1 |
| --- | --- | --- |
| 0 | 0 | 1 |
|1 | 1| 1 |

| XOR | 0 | 1 |
| --- | --- | --- |
| 0 | 0 | 1 |
|1 | 0 | 0 |

### Bit masking


```C
#define UP 1
// ... DOWN / LEFT / RIGHT / IN
#define OUT 32

if (direction & DOWN)
```

x << n == x * 2<sup>n</sup>
x >> n == x * 2<sup>-n</sup>

```C
int main() {
  printf("%d", (~12)+1); // prints -12
}
```

## Control Flow
...

sidenote: itoa (int to ascii) atoi (ascii to int)

## Makefiles and GDB
Makefile - compiling C program
GDB - C debugger

`gdb a.out` runs debugger on outputted binary

#### GDB commands
* refresh
* run
* layout next
* break POINT
* Step: next or n
* Step into a function: step
* Continue to next break point: continue
* Print a variable's value: print VARIABLE
* Print an array: *arr@len
* Watch a variable for changes: watch VARIABLE

