#include <stdio.h>
#include <stdlib.h>
#include "dynamic_array.h"

void add();
void delete();


int main(int argc, char** argv) {

    while (1) {
        int input = 0;
        printf("1. Add value\n2. Remove value\n3. Exit\n>  ");
        scanf("%d", &input);

        if (input == 1) {

            
            void add();
        }

        else if (input == 2) {
           
            void delete();
        }

        else if (input == 3) {
            return 0;
        }

        else {
            printf("Input not valid!\n");
        }
    }

    return 0;
}


void add() {

    double num_input = 0;
    printf("Enter a number:  ");
    scanf("%ld", &num_input);

    struct dynamic_array_t *dynamic = realloc(1, num_input * sizeof(struct dynamic_array_t));

    
    //debug
    printf("Input is %lf\n", num_input);
    
    //printf("%lf added at index %d, array size is %ld", &input, ??, sizeof(dynamic_array));

}

void delete() {

    double index_input = 0;
    printf("Enter an index:  ");
    scanf("ld", &index_input);

    //debug
    printf("Input is %lf\n", index_input);


    struct dynamic_array_t *dynamic = realloc(1, index_input * sizeof(struct dynamic_array_t));


    //printf("%lf removed from index %d, array size is %ld", &input, ??, sizeof(dynamic_array));

}