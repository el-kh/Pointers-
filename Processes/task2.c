#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/wait.h>

int main() {
    int pid, pid1;
    pid = fork();
	

    if (pid == 0) {
        printf("Child process: PID = %d\n", getpid());
        exit(0); 
    } 

	pid1 = fork();

	if (pid1 == 0) {
        printf("Child process  2: PID=%d\n", getpid());
        exit(2);  
    }

	waitpid(pid1, NULL, 0);
    printf("Parent: waited for Child 2 first (PID1=%d)\n", pid1);

	wait(NULL);
    printf("Parent: then waited for Child 1 (PID=%d)\n", pid);

	printf("Parent: PID=%d\n", getpid());
    return 0;
}



