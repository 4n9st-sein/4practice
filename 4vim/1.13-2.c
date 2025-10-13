
#include <stdio.h>
#include <stddef.h>

int main(void){
  printf("alignment of int = %ld\n", __alignof__ (int));
  printf("alignment of char = %ld\n", __alignof__ (char));
  printf("alignment of long double = %ld\n", __alignof__ (long double));
  return 0;
}

