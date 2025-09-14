#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/wait.h>


void task0() {
    int pid;
    printf("Printing forks, starting with fork1\n");

    pid = fork();
    printf("After 1st fork: PID=%d PPID=%d pid=%d\n", getpid(), getppid(), pid);
    printf("_");

    pid = fork();
    printf("After 2nd fork: PID=%d PPID=%d pid=%d\n", getpid(), getppid(), pid);
    printf("__");


    pid = fork();
    printf("After 3rd fork: PID=%d PPID=%d pid=%d\n", getpid(), getppid(), pid);
    printf("___");

    pid = fork();
    printf("After 4th fork: PID=%d PPID=%d pid=%d\n", getpid(), getppid(), pid);
    printf("____");

    sleep(1); 
}


void task1() {
    int pid = fork();

    if (pid == 0) {
        execl("/bin/ls", "ls", (char *)NULL);
        perror("execl failed");
        exit(1);
    } else {
        wait(NULL);
        printf("Parent process done\n");
    }
}


void task2() {
    int pid1, pid2;

    pid1 = fork();
   
    if (pid1 == 0) {
        execl("/bin/ls", "ls", (char *)NULL);
        exit(1);
    }

    pid2 = fork();
 
    if (pid2 == 0) {
        execl("/bin/date", "date", (char *)NULL);
        exit(1);
    }

    wait(NULL);
    wait(NULL);

    printf("Parent process done\n");
}

void task3() {
    int pid = fork();  

    if (pid == 0) {
        execl("/bin/echo", "echo", "Hello from the child process", (char *)NULL);
        exit(1);
    } else {
        wait(NULL);
        printf("Parent process done\n");
    }
}


void task4() {
    int pid = fork();  

    if (pid == 0) {
        execl("/bin/grep", "grep", "main", "test.txt", (char *)NULL);
        exit(1);
    } else {
        wait(NULL);
        printf("Parent process completed\n");
    }
}

// I am commenting previous functions just not to interfere with each other
int main() {
    task0();
    //task1();
    //task2();
    //task3();
    task4();
    return 0;
}
