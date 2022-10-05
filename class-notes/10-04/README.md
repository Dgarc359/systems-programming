# Structures

goals:
  understand structs
  learn how to declare
  understand pointers to structures
  struct: a collection of one or more variables

2D point in an XY axis
```C
struct point {
  int x;
  int y;
}
// requires 8 bytes to store
```

```C
// declare
struct point { ... } x, y,z; // define and instantiate in one line
struct point { ... }; struct point x,y,z; // define, then instantiate
```

can also use typedef to create alt name for any type

```C
typedef struct point point;
// whenever someone wants to use struct point now, they can just use point
```

```C
// Initializing
struct point maxpt = {320, 300};
```

```C
typedef struct { int x; int y; } point;
```

structures are similar to deterministic sized arrays with non-homogenous types

```C
maxpt.x // equal to 320
maxpt.y // equal to 300
```

```C
struct rect {
  struct point pt1;
  struct point pt2;
}
```

```C
// How do we init a rectangle
struct rect r1 = {
  struct pt1 = { 0, 0},
  struct pt2 = { 4, 5}
}
// OR
struct rect r1 = { 0, 0, 4, 5 }
```

```C
struct rect screen;
screen.pt1.x; // refers to x coord of the left corner vertex of rectangle "screen"
```

```C
struct point makepoint(int x, int y) {
  struct point temp; // stored in the stack

  temp.x = x; // vals of x and y
  temp.y = y;
  return temp; // return the whole 8 bytes, not a pointer, this is pass by value, not pass by reference, array returns the address to the beginning of the array, otherwise a struct passes all the data
}
```

```C
struct rect screen;
struct point middle;
struct point makepiint (int, int);

screen.pt1 = makepoint(0,0);
screen.pt2 = makepoint(XMAX, YMAX);
middle = makepoint((screen.pt1.x +)) // couldnt copy it down fast enough
```

```C
struct point addpoint(struct point p1, struct point p2){
  p1.x += p2.x;
  p1.y += p2.y;
  return p1;
}
```

```C
// check if point is inside rectangle
int ptinrect(struct point p, struct rect r) {
  return p.x >= r.pt1.x && p.x < r.pt2.x
      && p.y >= r.pt1.y && p.y < r.pt2.y; // returns 0 or 1
}
```

```C
#define min(a, b) ((a) < (b) ? (a) : (b))
#define max(a, b) ((a) > (b) ? (a) : (b)) //use parenthesis to keep precedence of operations

// gets nonstandard rectangle and returns canonical one
struct rect canonrect(struct rect r) {
  struct rect temp;
  temp.pt1.x = min(r.pt1.x, r.pt2.x);
  temp.pt1.y = min(r.pt1.y, r.pt2.y);

  temp.pt2.x = max(r.pt1.x, r.pt2.x);
  temp.pt2.y = max(r.pt1.y, r.pt2.y);
  return temp;
}
```

```C
struct point origin, *pp;
pp = &origin;
printf("origin is (%d, %d)\n", (*pp).x, (*pp).y);
printf("origin is (%d, %d)\n", pp->x, pp->y) // -> is equivalent to (*pp).x

struct rect r, *rp = &r;
r.pt1.x;

rp->pt1.x;
// equiv
(rp->pt1).x
```

## Pointers to functions

```C
void qsort(void *v[], int left, int right, 
  int (*comp)(void *, void *)) // pointer to a function `comp`, which compares 2 elements
```

imagine you have 10 files in your computer
1.txt
2.txt
.
.
10.txt
.
.
100.txt
strcmp will consider 100 lower than 2
numcmp will consider a string as a representation of numbers

which is why the 4th parameter of qsort is a pointer

```C
int numcmp(char *s1, char *s2) {
  double v1, v2;
  v1 = atof(s1);
  v2 = atof(s2);
  if (v1 < v2)
    return -1;
  else if 
}
```
void * is a 'superclass' of char *

in class activity
a) Write a C structure for a 2D points which stores the x-y coordinates of the point in two double values (x,y).

```C
typedef struct { // 16 bytes
  double x, y;
} point;
```
b) Write a C structure for a 2D triangle made of three 2D points.

```C
struct triangle = { // 16 * 3 bytes
  struct point p1;
  struct point p2;
  struct point p3;
}
```

c) Write a C function that receives a single triangle as its input argument and returns the perimeter of the triangle.

(x1, y1) (x2, y2)
distance formula sqrt((x2 - x1)^2 + (y2 - y1)^2)

```C
#include <math.h>
double getTrianglePerimeter(struct triangle tri) {
  double sideOne = sqrt(pow((tri.p1.x - tri.p2.x), 2) + pow((tri.p1.y - tri.p2.y), 2));
  double sideTwo = sqrt(pow((tri.p2.x - tri.p3.x), 2) + pow((tri.p2.y - tri.p3.y), 2));
  double sideThree = sqrt(pow((tri.p1.x - tri.p3.x), 2) + pow((tri.p1.y - tri.p3.y), 2));
  return sideOne + sideTwo + sideThree;
}
```

d) Write a C function that receives an array of triangles and the length of the array as its two input parameters and sorts the triangles in the array in the increasing order of their perimeters.

use qsort in lecture 5

```C
int triangle_comp(triangle* t1, triangle* t2) { //pass this into qsort function since it takes a pointer to a function as arg 4
  double diff = perimeter(t2) - perimeter(t2);
  if (diff > 0) return 1;
  else if (dif < 0) return -1;
  else return 0;
}
```

