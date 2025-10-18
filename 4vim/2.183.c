#include <stdio.h>
#include <stdlib.h>
int main(void) {
  int *p = malloc(4 * sizeof(int));
  for (int i = 0; i <= 3; i++) {
    p[i] = i;
  }
  free(p);
  return 0;
}

