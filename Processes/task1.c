#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

int main() {
    int pid;
    pid = fork();

    if (pid == 0) {
        printf("Child process: PID = %d\n", getpid());
        exit(0); 
    } 
    else {
        printf("Parent process: PID = %d\n", getpid());
    }

    return 0;
}

