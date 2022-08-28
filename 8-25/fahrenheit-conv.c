main () { // #TODO fix compilation issue with this file
  float fahr, cel;
  int lower, upper, step;

  lower = 0;
  upper = 300;
  step = 20;


  /**
   * %f = % w.p f
   *  w = width
   *  p = precision of decimals
   * 
   * %o for octal
   * %x for hexadecimal
   * %c for char
   * %s for char string
   * %% for % itself
   */
  fahr = lower;
  while (fahr <= upper) {
    cel = (5.0/9.0) * (fahr - 32.0);
    printf("%3.0f %6.1f\n", fahr, cel);
    fahr = fahr + step;
  }

  /**
   * char* = pointer to characters 
   */
}