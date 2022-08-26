#include <stdio.h>
#include <math.h>


int main () {

  int i, j;

  float twoDarr[9][2] = {
    {0.5, 0.5}, {0.5, 1}, {0.5, 2},
    {1, 0.5}, {1, 1}, {1, 2},
    {2, 0.5}, {2, 1}, {2, 2}
  };  

  for ( i = 0; i < 10; i++) {
    float height = twoDarr[i][0];
    float rad = twoDarr[i][1];
    float vol = M_PI * rad * rad * height;
    printf("%.1f\t%.1f\t%.2f\n", twoDarr[i][0], twoDarr[i][1], vol);
  }


  return 0;
}