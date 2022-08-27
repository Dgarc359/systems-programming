#include <stdio.h>

void main(void) {
  /**
   * https://www.youtube.com/watch?v=ayul1fmZd0Y
   * decimal (base 10) -> octal (base 8): 
   * 
   * 20 / 8 = 2R[4] || 20 % 8 = [4] LEAST SIGNIFICANT
   * Take result of division and modulus by 8, if it's smaller than 8, remainder is the original number: Proof ( 2 / 8 = 0.25 | 0.25 * 8 = 2 )
   * 2 % 8 = [2] MOST SIGNIFICANT
   * Order by Most -> Least Significant: 24 
   * 
   *
   * https://www.youtube.com/watch?v=4um7-QbpAQ8
   * decimal (base 10) -> hexadecimal (base 16):
   * 20 / 16 = 1R[4] || 20 % 16 = [4] LEAST SIGNIFICANT
   * Same as above, take result of division, modulus by 16 this time.
   * 1 % 16 = [1] MOST SIGNIFICANT
   * 
   * 14
   */
  printf("%d, %o, %x\n", 20, 20, 20);

  /**
   * 0x20 = hex
   * 2 * 16 = 32
   * 0 * 1 = 0
   * 32 + 0 = 32
   * 
   * octal:
   * 1: convert 20 to binary
   *  0010 0000
   * 2: convert binary to octal (every 3 bits, is one digit in octal)
   * 00 100 000
   * 0    4   0 = 40
   * 
   * hex: ??
   */
  printf("%d, %o, %x\n", 0X20, 0X20, 0X20);

  /**
   * decimal: ???
   * 
   * octal:
   *  20 ->
   *    binary 010 000 -> ????
   * 
   * hex: 
   * 20 ->
   *    binary 010 000 -> ????
   *      hex 10
   */
  printf("%d, %o, %x\n", 020, 020, 020);
}
