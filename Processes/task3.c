#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

void function1(void) {
    printf("function1 called\n");
}

void function2(void) {
    printf("function2 called\n");
}

int main() {
    atexit(function1);
    atexit(function2);
//    exit(0);
    printf("Main program is running...\n");
    printf("Main program is ending...\n");
    return 0;  
}



