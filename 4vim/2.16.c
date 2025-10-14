#include <stdio.h>
int check_bit(unsigned int x, int n) {
  int pow = 1;
  for (int i = 0; i < n + 1; i++){
    pow = pow * 2;
  }
  int ret = x % pow;
  return (int) ret /(int)((pow)/2);
}

int main(void) {
  int target = 0xD;
  printf("1st of %x is %d\n", target, check_bit(target, 0));
  printf("2nd of %x is %d\n", target, check_bit(target, 1));
  printf("3rd of %x is %d\n", target, check_bit(target, 2));
  printf("4th of %x is %d\n", target, check_bit(target, 3));
 return 0;
}

