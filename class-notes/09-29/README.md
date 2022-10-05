# Assignment notes

for sorting, chapter 5 part 2 notes have code for quick sort

array of char*, an array of char array pointers

if -s and -r are used together, then you should exit immediately

final sentence should not contain new line, only EOF

can use strstr in this assignment

don't need to worry about dots commas colons, matching words should be separated by space

strtok will tokenize for you

don't tokenize based off commas, colons, or dots or anything, just white space

strtok ex

```C
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
  char* input = strdup("In-N-Out has great burgers in fact");
  char* first_word = strtok(input, " ");
  printf("First word is %s\n", first_word);
  char* next_word;
  while(next_word = strtok(NULL, " "))
    printf("next word is %s\n", next_word);
}

char* strdup(char* input) {
  char* rv = (char*) malloc(1 + strlen(input));
  strcpy(rv, input);
  return rv;
}
```

Write a C function that receives a char* input string and a char* delimiter as its two input parameters, tokenizes the input using the delimiter, and returns the result of tokenization in the form of an array of char* types (char*[]).

My attempt
```C
// use strtok
// use malloc, strlen or strdup

// (my bad attempt...)
char** tokenize(char* input, char* delimiter) {
  char* return_array[];
  int idx = 0;
  char* first_word = strtok(input, delimiter);
  if(first_word)
    *(return_array + (idx++)) = strdup(first_word);
  
  char* next_word;
  while(next_word = strtok(NULL, delimiter))
    *(return_array + (idx++)) = strdup(next_word);


  return return_array;
}
```

Teacher solution
```C
char** tokenize(char* input, char* delimiter, int* num_of_tokens) {
  int counter;
  char* temp;
  char* input2 = strdup(input);
  strtok(input, delimiter); 
  counter = 1;
  for(; strtok(NULL, delimiter); counter++);
  printf("after counting: %d", counter);
  fflush(stdout);

  char** rv = (char**) malloc(counter * sizeof (char*));

  rv[0] = strdup(strtok(input2, delimiter));
  printf("token#%d is %s\n", 0, rv[0]);
  fflush(stdout);
  for(int i = 1; i < counter; i++){
    rv[i] = strdup(strtok(NULL, delimiter));
    printf("token#%d is %s\n", i, rv[i]);
    fflush(stdout);
  }
  
  *num_of_tokens = counter;

  return rv;
}

main() {
  char* input = strdup("test string");

  int n;
  char** tokens = tokenize(input, " ", &n);
  for(int i = 0; i < n; i++)
    printf("%d: %s\n", (i+1), )
}
```

you cannot tokenize a string twice