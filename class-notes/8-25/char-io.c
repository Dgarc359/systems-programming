#include <stdio.h>

/**
 * in C char is 8 bytes (1 bit)
 * 
 * get next input character from the standard input text stream:
 * c = getchar();
 * 
 * print single char to standard output text stream:
 * putchar(c);
 * 
 * char is represented by ascii code
 * https://theasciicode.com.ar/ (EOF - end of file = 255)
 * frequently used ascii:
 *  0, 1, 2, .. 9
 *  48, 49, 50, .. 57
 * 
 *  A, B, ... Z
 *  65, 66      90
 * 
 *  a, b,  ... z
 *  97, 98, ... 122
 */

void main () {
  // char c = getchar();
  // putchar(c);
  // print (int i = 'A'; i < 'Z'; i++) 
  //   printf("%d\n",i);

  putchar('h');
  putchar('e');
  putchar('l');
  putchar('l');
  putchar('o');

  // get a whole word separated by white space
  // tab or new line from the rest of input stream

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
    
    putchar(temp);
  }
}