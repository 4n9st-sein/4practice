#include <stdio.h>
#include <stddef.h>

int main(void){
  struct foo {
    char cl;
    int i;
    char c2;
    long double ld;
  };
  printf("offset of cl = %d\n", offsetof(struct foo, cl));
  printf("offset of i = %d\n", offsetof(struct foo, i));
  printf("offset of c2 = %d\n", offsetof(struct foo, c2));
  printf("offset of ld = %d\n", offsetof(struct foo, ld));
  
  printf("padding between cl and i= %d\n", offsetof(struct foo, i) - offsetof(struct foo,cl) - sizeof(char));
  printf("padding between i and c2= %d\n", offsetof(struct foo, c2) - offsetof(struct foo,i) - sizeof(int));
  printf("padding between c2 and ld= %d\n", offsetof(struct foo, ld) - offsetof(struct foo,c2) - sizeof(char));
  return 0;
}

