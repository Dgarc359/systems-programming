#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX_LINES 1000
char* lineptr[]; // externally defined because they're defined before main
int results[MAX_LINES];

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

int main(int argc, char** argv) {
  int except; // 0 or 1
  int sort; // 0 or 1
  int reversed; // 0 or 1
  int partial; // 0 or 1
  int first_occurence; // 0 or 1
  int matched = 0; // 0 or 1
  char* pattern;
  // ... other flags
  // handle command line arguments
  // check slide 41 from chapter 5 partII.pptx
  int nlines = readlines(lineptr, MAX_LINES); // this function will populate lineptr[] arr
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
