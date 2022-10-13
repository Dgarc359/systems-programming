#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "find.h"
char** lineptr; // externally defined because they're defined before main
int results[MAX_LINE];
int readlines(char* lineptr[], int nlines);

char* strstr_fully_matched(char* haystack, char* needle) {
  char* rv;
  char* padded_needle[strlen(needle) + 3];
  padded_needle[0] = ' ';
  strcpy(padded_needle + 1, needle);
  padded_needle[strlen(needle) + 1] = ' ';
  padded_needle[strlen(needle) + 2] = '\0';
  if(strncmp(haystack, padded_needle + 1, strlen(needle) + 1))
    return haystack; // needle at the beginning
  if((rv = strstr(haystack, padded_needle)) != NULL)
    return rv + 1; // needle is in the middle
  padded_needle[strlen(needle) + 1] = '\0';
  if((rv = strstr(haystack, padded_needle)) != NULL)
    return rv + 1; // needle is at the end
}

int get_line(char* line, int max);

int main(int argc, char** argv) {
  char line[MAX_LINE];
  long lineno = 0;
  int except = 0; // 0 or 1
  int sort = 0; // 0 or 1
  int reversed = 0; // 0 or 1
  int partial = 0; // 0 or 1
  int first_occurence = 0; // 0 or 1
  int matched = 0; // 0 or 1
  int numbered = 0;
  int sorted = 0;
  char* pattern;
  // ... other flags
  // long lineno =0;
  int c = 0;
  // int except ma= 0; 
  int number = 0;
  int found = 0;

//    while (argc > 0 && (*++argv)[0] == '-')
//      while (c = *++argv[0])
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
      else{
          // int test = 1000;
          // int* testtest = &test;
          // int* maximum_lines = &MAX_LINE;

          while (get_line(line, MAX_LINE) > 0) {
            lineno++;
            if((strstr(line, *argv) != NULL) != except)
              if (number)
                printf("%ld:", lineno);
              printf("%s", line);
              found++;
          }
        }
    }
    // return found;
  // handle command line arguments
  // check slide 41 from chapter 5 partII.pptx
  int nlines = readlines(lineptr, MAX_LINE); // this function will populate lineptr[] arr
  int no_of_results = 0;
  for(int i = 0; i< nlines; i++) {
    if(matched){
      if((strstr_fully_matched(lineptr[i], pattern) != NULL) != except) {
        results[no_of_results++] = i;
      }
    } else {
      if((strstr(lineptr[i], pattern) != NULL) != except) {
        results[no_of_results++] = i;
      }
      // not matched
    }
  }
  print_results(pattern, first_occurence, numbered, sorted, partial, reversed, no_of_results);
  return 0;
}

int get_line(char s[], int lim) {
  int c, i;

  for (i = 0; i < lim - 1 && (c = getchar()) != EOF && c != '\n'; i++)
    s[i] = c;
  if (c == '\n') {
    s[i] = c;
    i++;
  }
  s[i] = '\0';
  return i;
}

// read input lines
int readlines(char* lineptr[], int maxlines) {
  int len;
  int nlines;

  char* p;
  char* line[MAX_LINE];

  nlines = 0;

  while((len = get_line(line, MAX_LINE)) > 0)
    if (nlines >= maxlines || (p = alloc(len)) == NULL)
      return -1;
    else {
      line[len - 1] = '\0'; // del \n
      strcpy(p, line);
      lineptr[nlines++] = p;
    }
  return nlines;
}
