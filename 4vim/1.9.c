#include <stdlib.h>
#include <stdio.h>
#include <limits.h>
#include <ctype.h>

int main(int argc, char *argv[]){
    
    int i = 1;
    int sum = 0;
    while(argv[i] != NULL) {
        sum += atoi(argv[i]);
        i ++;
    }
    printf("%d\n", sum);
    return 0;
}