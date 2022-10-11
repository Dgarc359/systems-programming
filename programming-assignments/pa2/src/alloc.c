#include "find.h"

static char allocbuf[MAX_LINE];
static char* allocp = allocbuf; // next free pos.

char* alloc (int n ) {
  if (allocbuf + MAX_LINE - allocp >= n) {
    allocp += n;
    return allocp - n; // old p
  } else
      return 0;
}