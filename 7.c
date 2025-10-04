#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
#include <signal.h>

void getstatus(int pid);

int main(void){

    int count;
    pid_t pid_1 = fork();
    if (pid_1 == 0) {
        printf("pid; %d", getpid());
        while(1) {
            count ++;
        }
    } else {
        pid_t pid_2 = fork();
        if (pid_2 == 0) {
            printf("pid; %d", getpid());
            while(1) {
                count ++;
            }
        } else {
            wait(NULL);
        }
    }
}

