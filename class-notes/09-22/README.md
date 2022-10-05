# Multi Dimensional Arrays and Command Line Arguments


## Multi Dimenional Arrays
instead of using multidimensional arrays, 'ragged' arrays are used, which is an array containing a dynamic length array.

```C
int** daytab[i][j] /* row col */ = {
  {0, 30, 31, ..., 30},
  {0, 30, 28, ..., 30}
}

void month_day(int year, int yeardat, int *pmonth, int *pday) {
  int i, leap;
  leap = year % 4 == 0 && year%100 != 0 || year%400 == 0;
  for (i = 1; yearday > daytabl[leap][i]; i++)
    yearday -= daytab[leap][i];
  *pmonth = 1;
  *pday = yearday;
}
```

3D arrays have slightly different conventions

```C
#include <stdio.h>
char [2][3][4] = {'h', 'e', 'l', 'l', 'o', ' ',
                  'w', 'o', 'r', 'l', 'd', '\0'};

int main(void) {
  printf("%s\n", arr);
  return 0;
}
```

## Command Line Arguments

in C, argc is the # of args, argv is the array of chars that are the arguments

```C
#include <stdio.h>

main(int argc, char *argv[]) {
  int i;
  for (i = 1; i < argc; i++)
    printf("%s%s", argv[i], (i < argc -1) ? " " : "")
  // couldnt copy the rest of the code...
}
```

flags will simply be passed in with argv, probably look for '-' or '--' chars to determine they are flags

```C
main(int argc, char *argv[]) {
  long lineno =0;
  int c, except = 0, number = 0, found =0;
    while (argc > 0 && (*++argv)[0] == '-')
      while (c = *++argv[0])
    while (--argc > 0 && (*++argv)) {
      while (c = *++argv[0])
        switch (c) {
          case 'x':
            except = 1;
            break;
          case 'n':
            number = 1;
            break;
          default:
            printf("find: illegal opt", c);
            argc = 0;
            found = -1;
            break;
        }
      if(argc != 1)
        printf("usage: find -x -n pattern");
      else
        while (getline(line, MAXLINE) > 0) {
          lineno++;
          if((strstr(line, *argv) != NULL) != except)
            if (number)
              printf("%ld:", lineno);
            printf("%s", line);
            found++;
        }
    }
    return found;
}
```

## Class Activity
Write a C program called tokenize that gets the following command line arguments:

tokenize text delimiter [-n] [-sorted]

The program is supposed to

split the text into substrings separated by the given delimiter (a string made of letters except \t, \n, and white-space)
and list the substrings in stdout.
Optional flag -n makes the list numbered (1, 2, 3,...)
and flag -sorted sorts the tokens before listing them and printing them on the screen.

```C
#include <stdio.h>
#include <string.h>

main(int argc, char** argv) {
  if(argc < 3){
    fprintf(stderr, "tokenize:  too few CLAs\n")
    return 1;
  }
  char* text = argv[1];
  char* delim = argv[2];

  if(&delim[0] == '-') {
    fprintf(stderr, "tokenize: flag before delimiter char");
  }

  for(int i = 3; i < argc; i++)
    if(argv[i][0] != '-') {
      fprintf(stderr, "tokenize:  invalid CLAs\n");
      return 2;
    } else if (!strcmp("sorted", argv[i]+1){ // -sorted flag
      sorted = 1;
    } else if (!strcmp("n", argv[i]+1){ // -sorted flag
      numbered = 1;
    } else {
      fprintf(stderr, "tokenize:  invalid option\n");
      return 3;
    }

  // for(int i=0; i < argc; i++) {

  // }
}
