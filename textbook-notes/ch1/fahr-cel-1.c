#include <stdio.h>

/**
 * print fahrenheit - celsius table
 * for fahr = 0, 20, ..., 300 
 */

main () {
  int fahr, cel;
  int lower, upper, step;

  lower = 0;
  upper = 300;
  step = 30;

  fahr = lower;

  while (fahr <= upper) {
    /**
     * multiplying by 5 and _then_ dividing by 9 
     * this is on purpose, as multiplying 5/9 would yield 0, since it's int division
     * which would be multiplied with (fahr - 32) and always result in 0
     */
    cel = 5 * (fahr - 32) / 9;
    printf("%3d\t%6d\n", fahr, cel);
    fahr = fahr + step;
  }
}