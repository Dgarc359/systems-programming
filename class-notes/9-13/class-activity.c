#include<stdio.h>

int main(){
    char str[15] = "hello world!";

    char* p = &str[4];
    // p is a subarray of str, starting at index 4

    printf("%d %d %c %c %c", //calculations of printf start from right to left
        p - str, // the difference between p and str is 4
        p[-2] - 'a', // two cells to the left, - a means, l - a, which is 11
        p[3] - 4, // letter o - 4, 4 letters backwards in the alphabet
        *(p--), // print empty space, moves p back to o
        *(++p) // move p, print empty space
      );
}