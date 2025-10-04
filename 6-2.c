#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
#include <signal.h>
#include <sys/times.h>

static int count = 0;

int main() {
    struct tms start, end;
    clock_t t_start, t_end;
    int value = 0;
    t_start = times(&start);

    for (int i = 0; i < 5000; i ++){
        pid_t pid = fork(); 
        if (pid < 0) {
        perror("fork");
    } else if (pid == 0) {
        printf("hello! world count: %d\n", i);
        return 0;
    } else {
        printf("hello! world count; %d\n", i);
    }
    }
    
    
    t_end = times(&end);

    long ticks = sysconf(_SC_CLK_TCK);
    printf("User CPU time: %.2f sec\n", (end.tms_utime - start.tms_utime) / (double)ticks);
    printf("System CPU time: %.2f sec\n", (end.tms_stime - start.tms_stime) / (double)ticks);
}

