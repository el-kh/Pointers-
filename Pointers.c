#include <stdio.h>

// ex 1
  
int task1() {

    int a1 = 5;       
    int* p = &a1;   

    printf("Address stored in pointer: %p\n", p);   
    printf("Address of the variable: %p\n", &a1);  
    
    *p = 25;  

    printf("New value of a1: %d\n", a1);
    return 0;
}

// ex 2

int a2[5] = {2, 5, 7, 9, 23};
int* a2_p = a2;

int task2(){

    printf("Original array\n");
    for (int i = 0; i < 5; i++) {
        printf("%d ", *(a2_p + i));
    }
    printf("\n\n");

    for (int i = 0; i < 5; i++) {
        *(a2_p + i) = *(a2_p + i) * 2;  
    }

    printf("Modified array\n");
    printf("\nPrinting by pointer: \n");
    for (int j = 0; j < 5; j++){
        printf("%d ",  *(a2_p + j));
    }

    printf("\nPrinting by array name: \n");
    for (int j = 0; j < 5; j++){
        printf("%d ", a2[j]);
    }
    printf("\n");
    return 0;
}


// ex 3

int swap (int *a, int *b){

    printf("Printing original values: %d %d", *a, *b);

    int c;
    int* p = &c;
    
    *p = *a;
    *a = *b;
    *b = *p;
    printf("\nValues after swapping: %d %d", *a, *b);
    printf("\n");
    return 0;

}

// ex 4

int task4(){

    int a4 = 5;
    int* p = &a4;

    int** pp = &p;

    printf("\nPrinting value via Pointer: %d", *p);
    printf("\nPrinting value via Pointer's Pointer: %d", **pp);
    printf("\n");
    return 0;
}

// ex 5
int task5(){
    char str[] = "Hello";
    char* p = str;
    char* last = str + sizeof(str) - 1;

    for (int i = 0; i < sizeof(str); i++){
        printf("%c", *(p+i));
    }
    
    printf("\n");

    
    int count = 0;

    while(p < last){
        count++;
        p++;
    }
    printf("Counting the number of characters: %d \n", count);
    return 0;
}



int main() {
    printf("=== Task 1 ===\n");
    task1();

    printf("\n=== Task 2 ===\n");
    task2();

    printf("\n=== Task 3 ===\n");
    int a = 3;
    int b = 5;
    swap(&a, &b);

    printf("\n=== Task 4 ===\n");
    task4();

    printf("\n=== Task 5 ===\n");
    task5();
    return 0;
}
