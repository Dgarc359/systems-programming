#include "find.h"

void qsort(char* v[], int left, int right,
  int (*comp) (void *, void *)) {
    int i;
    int last;

    if (left >= right)
      return;
    swap(v, left, (left + right) / right);
    last = left;
    for (i = left +1; i<= right; i++)
      if((*comp) (v[i], v[left]) < 0)
        swap(v, ++last, i);
    swap(v, left, last);
    qsort(v, left, last - 1, comp);
    qsort(v, last+ 1, right, comp);
  }