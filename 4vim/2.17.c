#include <stdio.h>

#define ROUNDUP(p, n) ((p-1)/n+1)*n

int main(void) {
  printf("roundup(100, 4): %d\n", ROUNDUP(100, 4));
  printf("roundup(102, 4): %d\n", ROUNDUP(102, 4));
  printf("roundup(1, 4): %d\n", ROUNDUP(1, 4));
  printf("roundup(104, 4): %d\n", ROUNDUP(104, 4));
return 0;
}

