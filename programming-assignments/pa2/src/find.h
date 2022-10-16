#include<stdlib.h>
#include<string.h>
#include<stdio.h>
char* strstr_fully_matched(char* haystack, char* needle);
void print_results(char* pattern, long flags, int no_of_results);
extern char*lineptr[];
extern int results[];

enum cla_flags {
  MATCH = 1 << 0,
  NUMBER = 1 << 1,
  SORT = 1 << 2,
  REVERSE = 1 << 3,
  FIRST = 1 << 4,
  EXCLUDE = 1 << 5,
  CASE = 1 << 6,
  PARTIAL = 1 << 7,
};
