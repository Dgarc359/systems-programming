#include "find.h"

void print_results(char* pattern, int flags, int no_of_results) {

  char** sentences = (char**) malloc(no_of_results * sizeof(char*));
  for (int i = 0; i < no_of_results; i++)
    // sentences[i] = strdup(lineptr[results[i]]);

  if(flags & SORT) {
    // call quicksort on sentences...
  } else if (flags & REVERSE) {
    // reverse the sentences
  }
  for(int i = 0; i < no_of_results; i++){
    printf("in # of results");
    if(flags & NUMBER)
      printf("%d. ", results[i] + 1);
    if(flags & FIRST) {
    //   printf("@%d: ", strstr(lineptr[results[i]], pattern) - lineptr[results[i]]);
    }
    printf("%s\n", sentences[i]);
    }
}