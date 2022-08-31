#include <stdio.h>

void main (void) {
  char c;
  while((c = getchar()) != EOF) // OR EOF can be written as -1, can also break with !(c + 1)
    if(c >= 'A' && c <= 'Z') // in java: Character.isUppercase();
      c += ('a' - 'A');  // in java: Character.toLowercase();
    else if(c >= 'a' && c <= 'z') // // in java: Character.isLowercase();
      c -= ('a' - 'A'); // in java: Character.toupperCase();
    putchar(c);
}
