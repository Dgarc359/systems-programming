#include <stdio.h>
char get_word(char command[], int max_length) {
  char last_character;
  int i;
  for (i=0; i<max_length -1 && (command[i] = getchar()) != ' ' && command[i] !='\n'; i++)
  last_character = command[i];
  command[i] = '\0';
  return last_character;
}



int main() {
  char command[10];
  char str[400];
  char next_char;

  while(1) {
    next_char = get_word(command, 10);
    if(compare(command, "quit")) {
      break;
    } else if (compare(command, "check")) {
      if(next_char == '\n')
        printf("ERROR! Try again!\n");
      else {
        get_line(str, 400);
        printf("Checking %s...\n", str);
      }
    }
  }
}