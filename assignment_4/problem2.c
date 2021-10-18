#include <stdio.h>
#include <stdlib.h>
#include "dynamic_array.h"

#define BUF_SIZE 128

void add(dynamic_array_t* structArray, double *temp, int arraySize);
void delete();


int main(int argc, char** argv) {

    int arraySize = 1; 

    dynamic_array_t *structArray = calloc(1, sizeof(dynamic_array_t));
    structArray->data = calloc(1, sizeof(double));
    
    while (1) {
        int input = 0;
        printf("1. Add value\n2. Remove value\n3. Exit\n>  ");
        scanf("%d", &input);

        if (input == 1) {
            double *temp = calloc(arraySize, sizeof(double));

            printf("Enter a number:  ");
            scanf("%lf", temp);

            printf("You've entered: %f\n", *temp);

            arraySize += 1; 
            add(structArray, temp, arraySize);

            
        }
    }
}

void add(dynamic_array_t *structArray, double *temp, int arraySize) {
     // Add temp struct to struct array
    // printf("Array size is %d\n", arraySize - 1);
    
    structArray->data[arraySize-2] = *temp;
    structArray->size = (arraySize - 1);
    

    for (int i = 0; i < (arraySize - 1); i++) {
        printf("Element %d\n", i);

        printf("Value of data is %lf\n", structArray->data[i]);
        // printf("From add, it is %lf\n", *newArray[i].data);
        // newArray[i].size += 1;
        printf("Size is %d\n", structArray->size);
    }

}

void delete() {

    double indexInput = 0;
    printf("Enter an index:  ");
    scanf("%lf", &indexInput);

    //debug
    printf("Input is %f\n", indexInput);


    //struct dynamic_array_t *dynamic = realloc(1, indexInput * sizeof(struct dynamic_array_t));


    //printf("%lf removed from index %d, array size is %ld", &indexInput, d // Add temp struct to struct array
    // printf("Array size is %d\n", arraySize - 1);ynamic_array_t.size, sizeof(dynamic_array_t));

}