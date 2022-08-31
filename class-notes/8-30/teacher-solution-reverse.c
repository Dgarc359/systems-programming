#include <stdio.h>
#include <string.h>

void reverse(char str[]) {
  // int length = sizeof(str) -1 [not optimal]
  int length;
  // while (str[length++]);
  for (length = 0; str[length] != '\0'; length++);

  // length = strlen(str); this comes from <string.h>
  for (int start = 0, end = length -1; start <= end; start++, end--) {
    char c = str[start];
    str[start] = str[end];
    str[end] = c;
  }
}

void main (void) {
  char str[] = {'h', 'e', 'l', 'l', 'o', '\0'};
  printf("original string: %s\n", str);
  reverse(str);
  printf("reversed string: %s\n", str);
}