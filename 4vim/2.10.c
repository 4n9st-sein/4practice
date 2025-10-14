#include <stdio.h>
#include <string.h>

int L2B_int (int value){
  unsigned  char src[sizeof(int)];
  unsigned  char dst[sizeof(int)];
  memcpy(src, &value, sizeof(value));
  for(int i = 0; i < sizeof(int); i ++) {
    dst[i] = src[sizeof(int)-i - 1];
  }
  int result;
  memcpy(&result, dst, sizeof(result));
  return result;
}

void print_int(int value) {
  unsigned char *c =( unsigned char*) &value;
  for(int i = 0; i < sizeof(int); i ++) {
    printf("%x:", c[i]);
  }
  printf("\n");
  return ;
}

int main(void) {
  int i = 0x12345678;
  print_int(i);
  int j = L2B_int(i);
  print_int(j);
  return 0;
}

