#include <string.h>
#include <stdio.h>

extern char** lineptr;
extern int results[];
void print_results(char* pattern, int first_occurrence, int numbered, int sorted, int partial, int reversed, int no_of_results);
void swap(void *v[], int, int);
char* alloc(int n);
#define MAX_LINE 1000

