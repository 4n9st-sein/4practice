#include <stdlib.h>
#include <stdio.h>
#include <limits.h>
#include <ctype.h>

int main(int argc, char *argv[]){
    char *p = argv[1];
    while(*p != '\0') {
        if (!isdigit(*p)) {
            printf("not a number\n");
            exit(1);
        }
        p++;
    }
    long val = strtol (argv[1], NULL, 0);
    
    if (val == LONG_MIN || val == LONG_MAX) {
        perror("strtol");
        exit(1);
    }
    
    printf("%ld\n", val);
    return 0;

}
