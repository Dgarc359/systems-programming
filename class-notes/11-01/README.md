## Class Activity

Write a C program that uses "-i fmt" (for input format) and "-o fmt" (for output format) command-line arguments to specify the input/output formats and converts tabular data from one format to the other. Supporting formats are csv and txt.

`./convert -i txt -o csv`

```C
#include <string.h>
#include <stdio.h>

main (int argc, char** argv) {
  while(--argc > 0 && (*++argv)) {
    while(c = *++argv[0]) {
      switch(c) {
        case 'i':
          char* in = *++argv;
          break;
        case 'o':
          char* out = *++argv;
          break;
      }
    }
  }

  char* tokenized = strtok(in, in === "txt" ? "\t" : ",");

}
```

soltn

```C
#define MAX_LINE_LENGTH
#define MAX_CELL_LENGTH 20
main(int argc, char* argv[]) {
  char in_ext[4], out_ext[4];
  char line[MAX_LINE_LENGTH];
  char cell[MAX_CELL_LENGTH];
  char* rest;
  if(argc < 5) {
    fprintf(stderr, "convert: too few args\n");
    exit(1);
  }
  else if(argc > 5) {
    fprintf(stderr, "convert: too many args\n");
    exit(1);
  }
  if(!strcmp(argv[1], "-i")) {
    strncpy(in_ext, argv[2], 3);
    strncpy(out_ext, argv[4], 3);
  } else if(!strcmp(argv[1], "-o")) {
    strncpy(out_ext, argv[2], 3);
    strncpy(in_ext, argv[4], 3);
  } else {
    fprintf(stderr, "convert: Fatal error, usage -i in_ext -o out_ext\n");
    exit(1);
  }
  frpintf(stderr, "convert: in format is %s, out format is %s\n", in_ext, out_ext);
  if(!strcmp(in_ext, "csv") && !strcmp(out_ext, "txt")) {
    while(fgets(line, MAX_LINE_LENGTH, stdin)) {
      while(sscanf(line,"%[^,],&[^\n]\n", cell, line) == 2)
        printf("%s\t", cell); // internal cell followed by tab
      printf("%s\n", cell); //alst cell followed by new line
    }
  } else if(!strcmp(in_ext, "txt") && !strcmp(out_ext, "csv")) {
    while(fgets(line, MAX_LINE_LENGTH, stdin)) {
      while(sscanf(line, "%[^\t]\t&[^\n]\n", cell, line) == 2)
        printf("%s,", cell); //internal cell followed by tab
      printf("%s\n", cell); // last cell followed by new line
    }
  } else if (!strcmp(in_ext, out_ext){
    while((c = getchar()) != EOF)
      putchar(c);
  } else {
    fprintf(stderr, "convert: fatal error! usage: -i in_ext -o out_ext, only supported usage is txt or csv");
    exit(1);
  }

}
```
note: use normalizer as a subroutine somewhere in assignment 3

## File Access

```C
FILE *fp;
FILE *fopen(char* name, char* mode);
```

## Notable Methods
* fgets
* fputs
* ferror
* strcat
* strncat
* strchr
* strnchr


```C
char* strip(char* input) {
  char* rv = (char*) malloc (strlen(input) + 1);
  int left, right, flag = 1;
  for(left = 0, right = strlen(input) -1; left < right && flag;) {
    if(input[left] == ' '){
      left++;
      flag = 1;
    }
    else flag = 0;
    if(input[right] == ' '){
      right--;
      flag = 1;
    } else flag = 0;
  }
  strncpy(rv, input + left, right - left + 1);
  return rv;
}
```
