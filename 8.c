#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
#include <signal.h>

int main(void){
    int memory[2] = {100, 100};

    printf("memory(%p, %p): %d, %d\n", memory, memory+1, memory[0], memory[1]);

    pid_t pid = fork();
    if (pid < 0){
        perror("fork()");
        exit(1);
    } else if (pid == 0) {
        printf("child memory(%p, %p): %d, %d\n", memory, memory+1, memory[0], memory[1]);
        memory[1] = 50;
        printf("child memory(%p, %p): %d, %d\n", memory, memory+1, memory[0], memory[1]);
    } else {
        printf("memory(%p, %p): %d, %d\n", memory, memory+1, memory[0], memory[1]);
        memory[1] = 150;
        printf("memory(%p, %p): %d, %d\n", memory, memory+1, memory[0], memory[1]);
    }
    return 0;
}