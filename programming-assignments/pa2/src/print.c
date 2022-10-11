#include "find.h"

void print_results(char* pattern, int first_occurrence, int numbered, int sorted, int partial, int reversed, int no_of_results) {

  char* sentences[] = (char**) malloc(no_of_results*sizeof(char*));
  for (int i = 0; i < no_of_results; i++)
    sentences[i] = strdup(lineptr[results[i]]);
  if(sorted) {
    // call quicksort on sentences...
  } else if (reversed) {
    // reverse the sentences
  }
  for(int i = 0; i < no_of_results; i++){
    if(numbered)
      printf("%d. ", results[i] + 1);
    if(first_occurrence) {
      prinft("@%d: ", strstr(lineptr[results[i]], pattern) - lineptr[results[i]]);
    }
    printf("%s\n", sentences[i]);
    }
}