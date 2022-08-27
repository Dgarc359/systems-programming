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
  printf("%d, %o, %x\n", 20, 20, 20); // prints 20, 24, 14

  /**
   * hexadecimal -> decimal: (NOTE: 0x is just the identifier for hex values in C, for our purposes, we can ignore it in calculations)
   * 2 * 16 = 32
   * 0 * 1 = 0
   * 32 + 0 = [32]
   * OR
   * convert each digit to binary first: (SIMPLER)
   * 20 = 0_0_1_0 | 0_0_0_0
   * combined = 0010 0000 = [32]
   * 
   * octal:
   * 1: convert 20 to binary
   *  0010 0000
   * 2: convert binary to octal (every 3 bits, is one digit in octal)
   * 00 100 000
   * 0    4   0 = [40]
   * 
   * hex: 0x20 (0x is ignored) = [20] 
   */
  printf("%d, %o, %x\n", 0X20, 0X20, 0X20); // prints 32, 40, 20

  /**
   * https://www.youtube.com/watch?v=YCM2JReWS10
   * octal -> decimal:
   * octal:
   *  20 ->
   *    octal binary (groups of 3) 010 000 ->
   *        decimal [16]
   * 
   * octal -> octal: ignore leading 0 = [20]
   *
   * octal -> hex: 
   * 20 ->
   *    octal binary (groups of 3) 010 000 ->
   *      hex binary (groups of 4) 0001 0000 ->
   *        decimal [10]
   */
  printf("%d, %o, %x\n", 020, 020, 020); // prints 16, 20, 10
}
