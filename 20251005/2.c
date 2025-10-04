#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>

void getstatus(int pid);

int main(void){
    int pid_t = getpid();
    
    getstatus(pid_t);

    pid_t = fork();

    if (pid_t < 0) {
        perror("fork()");
        exit(1);
    }
    else if (pid_t == 0) {
    printf("here is child\n");
    getstatus(getpid());
    sleep(10);
    } else {
        wait(NULL);
        printf("here is parent\n");
        getstatus(getpid());
        getstatus(pid_t);
    }
    return 0;
}

void getstatus(int pid){
    char path[64];
    snprintf(path, sizeof(path), "/proc/%d/stat", pid);
    FILE *fd = fopen(path, "r");
    
    if (fd == NULL) {
        perror("fopen");
        exit(1);
    }
    char comm[256], state;

    fscanf(fd, "%d %s %c", &pid, comm, &state);
    fclose(fd);

    printf("PID: %d, Name: %s, State; %c\n", pid, comm, state);
    return ;
}