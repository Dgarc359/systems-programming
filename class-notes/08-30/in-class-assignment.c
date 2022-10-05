#include <stdio.h>

int flipChars(int x);
void reverse(char str[]);

main () {
  char temp;
  /**
   * press ctrl + d to close buffer without inputting newline ('\n') 
   */
  while(1){
    temp = getchar(); // until you press enter, data is in buffer stream
    if ( temp == ' ' 
      || temp == '\t' 
      || temp == '\n' 
      || temp == EOF
    )
      break;
    
    // putchar(temp);
    temp = flipChars(temp);
    putchar(temp);
  }

  reverse("test");

}

int flipChars(int c) {
  if (c >= 'A' && c <= 'Z')
    return c + 'a' - 'A';
  else
    return c - 'a' + 'A';
}

void reverse(char str[]) {
  char reversed[0] = "";
  for (int i = 0; str[i] == '\0'; i++) {
    char *strcat(reversed, i);
  }
  printf("%s", reversed);
}

void remove_second_half(char str[]) {
  // ran out of time
}