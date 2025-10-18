#include <stdio.h>
#include <stdlib.h>
int **create_java_array(int m, int n) {
  int **ret;
  ret = malloc(m*sizeof(int *));
    if(ret == NULL) {
     perror("malloc() failed"); return NULL;
     }
  for(int i =0; i < m; i ++){
    ret[i] = malloc(n*sizeof(int));
    if(ret[i] == NULL) {
    perror("malloc() failed"); return NULL;
    }
  }
  return ret;
}
int main(void) {
  int **p;
  p = create_java_array(2, 3);
  for(int i = 0; i < 2; i ++) {
    for(int j = 0; j < 3; j ++) {
      p[i][j] = j;
    }
  }
  for(int i = 0; i < 2; i ++) {
    for(int j = 0; j < 3; j ++) {
      printf("array[%d][%d]=%d\n", i , j,p[i][j]);
    }
   }
  for(int i = 0; i < 2; i ++) {
    free(p[i]);
  }
  free(p);
   return 0;
}
