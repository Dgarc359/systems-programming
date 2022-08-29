#include <stdio.h>

/** copy I/O; V1 */
main() {
  int c; // c is declared as int to hold EOF value, which is defined as an int in <stdio.h>

  c = getchar();
  while (c != EOF) {
    putchar(c);
    c = getchar();
  }
}
