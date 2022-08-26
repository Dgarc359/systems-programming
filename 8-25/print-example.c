#include <stdio.h>

void main(void) {
  /**
   * octal:
   * 20 % 8 = 4
   * 20 / 8 = 2
   * 2 % 8 = 2
   * 20, 24 
   * 
   * hex:
   * 20 % 10 = 4
   * 20 / 16 = 1
   * 1 % 16 - 1
   * 
   * 20, 24, 14
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