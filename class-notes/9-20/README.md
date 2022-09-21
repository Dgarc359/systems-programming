# Rewriting strlen using pointers

```C
int strlen (char *s) {
  char *p = s;
  while (*p != '\0')
    p++;
  return p - s;
}
```

malloc implemented with next spit[sic]? algorithm

`void* malloc(int n) // std.h`
`void free(void*);`

stack frame will free memory when functions go out of scope, even if you make a pointer to memory in a function in the stack, the pointer will point to memory that isn't legitimate once the memory is freed

when you create a variable, ask yourself if it should go in the heap or stack.
should you use malloc to store it in the heap?

do not store important info inside a function's local variables

```C
/* returns <0 if s<t, 0 if s==t, >0 if s>t */
int strcmp(char *s, char *t) { // char *s is an idiom for an array of chars called s
  int i;
  for (i = 0; s[i] == t[i]; i++)
    if (s[i] == '\0')
      return 0;
  return s[i] - t[i];
}

// with pointers
int strcmp(char *s, char *t) { // char *s is an idiom for an array of chars called s
{
  for (; *s == *t; s++, t++)
    if(*s == '\0')
      return 0;
  return *s - *t;
}
```


# Pointer Arrays; Pointers to Pointers
```C
# include <stdio.h>
# include <string.h>

#define MAXLINES 5000

char *lineptr[MAXLINES]; // goes to static data section

int readlines(char *lineptr[], int nlines);
void writelines(char *lineptr[], int nlines);

void qsort(char *lineptr, int left, int right);

main() {
  int nlines;
  if((nlines = readlines(lineptr, MAXLINES)) >= 0) {
    qsort(lineptr, 0, nlines-1)
  }
}
// i couldnt keep up with the slides
void writelines(char *lineptr[], int nlines)
{
  int i;
  for (i =0; i < nlines; i++)
    printf("%s\n", lineptr[i]);
}

void qsort(char *v[], int left, int right) {
  int i, last;
  void swap (char * v[], int i, int j);

  if (left >= right)
    return;
  swap(v, left, (left + right)/ 2);
  last = left;
  for (i = left + 1; i <= right; i++)
    if(strcmp(v[i], v[left]) < 0)
      swap(v, ++last, i);
  swap(v, left, last);
  qsort(v, left, last-1);
  qsort(v, last +1, right);
}
```

# Class Activity

Write a C function with the following signature that receives a string from input, stores its reverse in the heap and returns the address of its reverse copy as the return value.

```C
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char* str_dup_and_reverse(char input[]){
  int n = strlen(input);
  char* dup = (char*) malloc(n + 1);
  for(int i = n -1; i >= 0; i--)
    dup[i] = input[j++];
  dup[n] = '\0';
}
```

2. Write a C program that gets a list of at-most 100 sentences followed by EOF from stdin. The program should reverse each sentence print out the list of all sentences in reverse order.

```C
#define MAX_LEN 1000
char* lineptr[100];

void get_line(char* line, int max) {
  char c;
  int i = 0;
  while(i < max && (c = getchar()) !== EOF) {
    if (c == '\n')
      break;
    line[i++] = c;
  }
  line[i] = '\0';
}

int read_lines(char* lineptr[], int limit){
  char line[MAX_LEN]; // stack
  for(int i =0; i < limit; i++){
    get_line(line, MAX_LEN);
    lineptr[i] = strdup(line);
  }
}

void reverse(char* str) {
  for(int first = 0, last = strlen(str) -1; first < last; first++, last--) {
    char temp = str[first];
    str[first] = str[last];
    str[last] = temp;
  }
}
void write_lines(char * lineptr[], int len) {
  for (int i = len -1; i >= 0; i--) {
    printf("%s\n", reverse(lineptr[i]));
    printf("%s\n", lineptr[i]);
  }
}
int main(void) {
  int num = read_lines(lineptr, 100);
  write_line(lineptr, num); // should reverse the order of lines
  for (int i =0; i < num; i++)
    free(lineptr[i])
}
```
