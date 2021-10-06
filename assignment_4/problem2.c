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

    dynamic_array_t structArray[0];
    double numInput = 0; 
    dynamic_array_t* ptr = malloc(sizeof(dynamic_array_t));
    printf("Enter a number:  ");
    scanf("%ld", ptr->data);
 

    struct dynamic_array_t *dynamic = realloc(ptr, numInput * sizeof(dynamic_array_t));


}

void delete() {

    double indexInput = 0;
    printf("Enter an index:  ");
    scanf("ld", &indexInput);

    //debug
    printf("Input is %lf\n", indexInput);


    //struct dynamic_array_t *dynamic = realloc(1, indexInput * sizeof(struct dynamic_array_t));


    //printf("%lf removed from index %d, array size is %ld", &indexInput, dynamic_array_t.size, sizeof(dynamic_array_t));

}