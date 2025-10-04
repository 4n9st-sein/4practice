#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>

void getstatus(int pid);

int main(void){
    int fds[2];
    const int BSIZE = 100;
    char buf[BSIZE];
    int status;

    status = pipe(fds);
    if (status == -1) {
        perror("pipe()");
        exit(1);
    }
    pid_t pid_p = getpid();
    
    getstatus(pid_p);

    pid_t pid = fork();

    if (pid < 0) {
        perror("fork()");
        exit(1);
    }
    else if (pid == 0) {
    close(fds[0]);
    printf("here is child\n");
    getstatus(getpid());
    sleep(10);
    getstatus(pid_p);
    write(fds[1], "Hello world\n", 12);
    exit(1);
    } else {
        close(fds[1]);
        read(fds[0], buf, BSIZE);
        printf("here is parent\n");
        printf("read message is %s", buf);
        getstatus(getpid());
        getstatus(pid);
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