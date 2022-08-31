#include <stdio.h>

/** copy I/O; V2 */
main() {
  int c; // c is declared as int to hold EOF value, which is defined as an int in <stdio.h>

  while ((c = getchar()) != EOF) 
    putchar(c);
}
