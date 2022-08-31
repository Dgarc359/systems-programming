#include <stdio.h>

void remove_second_half(char str[]){
  int length;
  for (length = 0; str[length] != '\0'; length++)
    str[length/2] = (char)NULL; // '\0;0;
}

void main(void) {
  char str[] = {'h', 'e', 'l', 'l', 'o', '\0'};
  printf("original string: %s\n", str);
  remove_second_half(str);
  printf("reversed string: %s\n", str);
}
