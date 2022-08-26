#include <stdio.h>
#include <math.h>
#define volume(h, r) ((h) * (r) * (r) * M_PI)

void main (void){
  for(float height = 0.5; height <= 2; height *= 2)
    for(float radius = 0.5; radius <= 2; radius *= 2) {
      printf("%.1f\t%.1f\t%.2f%s", height, radius, volume(height, radius),
        (height == 2 && radius == 2) ? "" : "\n");
      }
}