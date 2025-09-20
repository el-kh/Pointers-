#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>

int main() {
    int status;
    int pid1, pid2;

    pid1 = fork();
    if (pid1 == 0) {
        printf("Child 1: PID=%d\n", getpid());
        exit(7);   
    }

	pid2 = fork();
	if (pid2 == 0) {
        printf("Child 2: PID=%d\n", getpid());
        exit(15);  
    }
    
    if (pid1 > 0 && pid2 > 0) {
        waitpid(pid1, &status, 0);
        printf("Parent: Child 1 exited with status %d\n", WEXITSTATUS(status));

        waitpid(pid2, &status, 0);
        printf("Parent: Child 2 exited with status %d\n", WEXITSTATUS(status));

        printf("Parent: PID=%d finished waiting\n", getpid());
    }

    return 0;
}

