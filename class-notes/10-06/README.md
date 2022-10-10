#

Readlines function, slide 23 chapter 5 is good for sorting lines of strings

Handling CLAs (command line args) slide 41

compare two strings, use strstr

the pattern is the last argument

store indices of lines you want to print

```C
// find.h
#include <stdlib.h>
extern char* lineptr[];
extern int results[];


// find.c
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX_LINES 1000
char* lineptr[]; // externally defined because they're defined before main
int results[MAX_LINES];

char* strstr_fully_matched(char* haystack, char* needle) {
  char* rv;
  char* padded_needle[strlen(need) + 3];
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

// print.c
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
    if(first_occurence) {
      prinft("@%d: ", strstr(lineptr[results[i]], pattern) - lineptr[results[i]]);
    }
    printf("%s\n", sentences[i]);
    }
}

```
CLAs once @ very beginning of running your program
stdin -- cgetchar / getline / fgets

assignment 2 only has CLAs

ctrl + D flushes input stream buffer, the 2nd time you press it, it adds EOF to input stream

## Linked List

```C
struct node { // self referential struct (linked list)
  int value;
  struct node* next;
}

typedef struct node node;

void append(node** head, int value) { // assume list is not empty
  if((*head) == NULL) {
    (*head) = (node*) malloc(sizeof(node));
    (*head) -> value = value;
    (*head) -> next = NULL;
    return;
  }
  while((*head) -> next) {
    (*head) = (*head) -> next;
  }
  (*head) -> next = (node*) malloc(sizeof(node));
  (*head) -> next -> value = value;
  (*head) -> next -> next = NULL;
}

int main() {
  // empty linked list
  node * head = NULL;

  // LL size 1 containing 1 elem of value 10
  node * head = (node*) malloc(sizeof(node));
  head -> value = 10;
  head -> next = NULL;

  // append 15 to previous list
  // append(head, 15);
  append(&head, 15); // pass by ref
}

