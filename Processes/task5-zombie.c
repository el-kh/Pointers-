#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>

int main() {
    int  pid = fork();

    if (pid == 0) {
        printf("Child: PID=%d exiting now...\n", getpid());
        exit(0);
    } else if (pid > 0) {
        wait(NULL);
        printf("Parent: PID=%d, no zombie created\n", getpid());
        sleep(90); 
    }

    return 0;
}

