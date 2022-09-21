#define BUFSIZE 400
#include "balance.h"

char buf[BUFSIZE];
int bufp = 0;

int push(int element){
  if (bufp >= BUFSIZE)
    printf("stack is at max limit");
  else
    buf[bufp++] = element;
}

int pop(void){
  if(bufp > 0) {
    buf[--bufp] = NULL;
    return 0;
  } 
  else
    return 1;
}

int peek() {
  return buf[bufp];
}

