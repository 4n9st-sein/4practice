#include <stdio.h>

struct rectangle {
  int x, y, height, width;
};
struct triangle {
  int x1, y1, x2, y2, x3, y3;
}

struct circle {
  int x, y, z;
}

union shape {
  struct rectangle r;
  struct triangel t;
  struct circle c:
}

