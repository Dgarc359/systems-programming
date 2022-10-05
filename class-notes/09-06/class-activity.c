#define BUFSIZE 1000

char buf[BUFSIZE];//buffer for left parentheses

int bufp;//next free position in buf

int getch(void) {
  return (bufp > 0) ? buf[--bufp] : getchar();
}

/**
 * remove elem from stack 
 * @param c 
 */
void ungetch(int c) {
  if (bufp >= BUFSIZE)
    printf("ungetch: too many chars\n");
  else
    buf[bufp++] = c;
}

int is_balanced(char input[]){
  int LEN = sizeof input / sizeof *input;
  for (int i = 0; LEN - 1; i++) {
    if (input[i] == '(') {
      ungetch('(');
    }
    else if (input[i] == ')') {
      getch();
    }
  }
  if ((sizeof buf / sizeof *buf) != 0) {
    return 0;
  }
  else {
    return 1;
  }
}