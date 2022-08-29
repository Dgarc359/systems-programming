#include <stdio.h>

/**
 * refactoring fahr-cel-1 to use floating point division
 * this will yield more accurate conversions 
 */

int main(int argc, char const *argv[])
{
  float fahr, cel;
  float lower, upper, step;

  lower = 0;
  upper = 300;
  step = 20;

  fahr = lower;
  while(fahr <= upper) {
    cel = (5.0/9.0) * (fahr - 32.0);
    printf("%3.0f %6.1f\n", fahr, cel);
    fahr = fahr + step;
  }

  return 0;
}
