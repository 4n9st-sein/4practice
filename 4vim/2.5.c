#include <stdio.h>
#include <stdlib.h>
int main (int argc, char *argv[]) {
  int i; 
  int *data = malloc(sizeof(int) * (argc - 1));
    for (i = 1; i < argc; i ++) {
      data [i -1] = atoi (argv[i]);
    }
    for (i = 1; i < argc ;i ++) {
      printf("data[%d]:%d\n", i-1, data[i-1]);      
    }
    free(data);

    return 0;
}

