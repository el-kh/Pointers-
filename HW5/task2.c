#include <stdio.h>
#include <stdlib.h>

int main() {
    int n;
    float avg = 0;
    printf("Enter number of elements: ");
    scanf("%d", &n);

    int *arr = (int*)calloc(n,sizeof(int));

    if (arr==NULL){
    	printf("Memory allocation failed: ");
	return 1;
    }

    printf("Array after calloc: ");
    for(int i = 0; i<n; i++){
    
    	printf("%d  ", arr[i]);
    }

    printf("\n");

    printf("Enter  %d integers: \n", n);
    for(int j = 0; j < n; j++){

	    scanf("%d", &arr[j]);
	    avg += arr[j];
        }
    
    printf("Updated array: ");
    for (int i = 0; i < n; i++)
        printf("%d ", arr[i]);
    printf("\n");

    avg = avg/n;

    printf("Avarage is %.2f\n", avg);
    
    free(arr);

    return 0;


    }
