#include <string.h>
#include <stdio.h>

extern char** lineptr;
extern int results[];

enum cla_flags {
  MATCH = 1,
  NUMBER = 2,
  SORT = 4,
  REVERSE = 8,
  FIRST = 16,
  EXCLUDE = 32,
  CASE = 64,
  PARTIAL = 128,
};

void print_results(char* pattern, int flags, int no_of_results, int results[]);
void swap(void *v[], int, int);
char* alloc(int n);
#define MAX_LINE 1000

