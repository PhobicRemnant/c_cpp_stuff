#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int *random_array(size_t n){

    // Create a pointer to the array
    int *arr = malloc(sizeof(int)*n);

    if(arr == NULL){
        // Memory could not be allocated
        // Handle error
        int fail[] ={0};
        return fail;
    }

    for(int i = 0 ; i < n ; i++){
        *(arr + i) = rand() % 11; 
    }

    return arr;

}

void print_array(int *p, int n){
    printf("Random filled array:\n");

    for(int i = 0; i < n ; i++){
        printf("Number: %d\n", *(p+i));
    }
}

int main(){

    int number = 10;
    time_t t;

    // Init the random number genertor
    srand((unsigned) time(&t));

    // Create random array
    int *arr = random_array(number);

    // Print random array
    print_array(arr, number);

}