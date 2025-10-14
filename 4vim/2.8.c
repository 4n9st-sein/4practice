#include <stdio.h>
int twice(int x) {return x * 2;}
int map(int p[], int size, int (*func) (int)) {
  for(int i = 0; i < size ; i ++) {
    p[i] = func(p[i]);
  }
  return 0;
}
int main(void)
{
  int i;
  int a [5] = {10, 20, 30, 40, 50};
  map (a, 5, twice);
  for (i= 0; i < 5; i ++) {
    printf("a[%d] = %d\n", i, a[i]);
  }
}
