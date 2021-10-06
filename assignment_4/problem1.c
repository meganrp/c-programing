#include <stdio.h>
#include <stdlib.h>
#include "problem_1.h"


int main(int argc, char** argv) {

    first_return  ();
    second_return ();
    third_return ();
    fourth_return ();
    fifth_return ();
    sixth_return ();
    seventh_return ();
    eighth_return ();
    nineth_return ();
    tenth_return ();

    return 0;
}

void first_return() {

    printf("Running first function!\n");
    int* ptr; 
    ptr = (int*)malloc(sizeof(int));

    if (ptr == NULL) {
        printf("Memory can not be allocated\n");
        exit(0);
    }

    else {
        printf("Memory allocated!\n");
        *ptr = 1;
        printf("The value of pointer is %d\n", *ptr);

    }

    free(ptr);
    printf("Memory freed!\n");
}

void second_return() {

    printf("Running second function!\n");
    char input[BUFF];
    printf("Enter an interger for the size of the second function: ");
    fgets(input, BUFF, stdin);

    int* ptr = (int*)malloc(sizeof(input));

    if (ptr == NULL) {
        printf("Memory can not be allocated\n");
        exit(0);
    }

    else {
        printf("Memory allocated!\n");
        *ptr = 1;
        printf("All values set to %d\n", *ptr);
    }
    free(ptr);
    printf("Memory freed!\n");

}

void third_return() {

    printf("Running third function!\n");
    char r = 0, c = 0;
    printf("Enter an interger for the number of rows for the third function: ");
    fgets(&r, BUFF, stdin);
    printf("Enter an interger for the number of columns for the third function: ");
    fgets(&c, BUFF, stdin);

    int* ptr = (int *)malloc((r * c) * sizeof(int));

    if (ptr == NULL) {
        printf("Memory can not be allocated\n");
        exit(0);
    }

    else {
        printf("Memory allocated!\n");
        *ptr = 1;
        printf("All values set to %d\n", *ptr);
    }
    free(ptr);
    printf("Memory freed!\n");

}

void fourth_return() {

    printf("Running fourth function!\n");
    char r = 0, c = 0, s = 0;
    printf("Enter an interger for the number of rows for the third function: ");
    fgets(&r, BUFF, stdin);
    printf("Enter an interger for the number of columns for the third function: ");
    fgets(&c, BUFF, stdin);
    printf("Enter an interger for the number of spaces for the third function: ");
    fgets(&s, BUFF, stdin);

    int* ptr = (int *)malloc((r * c * s) * sizeof(int));

    if (ptr == NULL) {
        printf("Memory can not be allocated\n");
        exit(0);
    }

    else {
        printf("Memory allocated!\n");
        *ptr = 1;
        printf("All values set to %d\n", *ptr);
    }
    free(ptr);
    printf("Memory freed!\n");

}

void fifth_return() {

    printf("Running fifth function!\n");
    double* ptr = (double*)malloc(sizeof(double));

    if (ptr == NULL) {
        printf("Memory can not be allocated\n");
        exit(0);
    }

    else {
        printf("Memory allocated!\n");
        *ptr = 1.61;
        printf("The value of pointer is %f\n", *ptr);

    }

    free(ptr);
    printf("Memory freed!\n");
}

void sixth_return() {

    printf("Running sixth function!\n");
    char input[BUFF];
    printf("Enter an interger for the size of the sixth function: ");
    fgets(input, BUFF, stdin);

    double* ptr = (double*)malloc(sizeof(input));

    if (ptr == NULL) {
        printf("Memory can not be allocated\n");
        exit(0);
    }

    else {
        printf("Memory allocated!\n");
        *ptr = 1;
        printf("All values set to %f\n", *ptr);
    }
    free(ptr);
    printf("Memory freed!\n");

}

void seventh_return() {

    printf("Running seventh function!\n");
    char r = 0, c = 0;
    printf("Enter an interger for the number of rows for the seventh function: ");
    fgets(&r, BUFF, stdin);
    printf("Enter an interger for the number of columns for the seventh function: ");
    fgets(&c, BUFF, stdin);

    double* ptr = (double *)malloc((r * c) * sizeof(double));

    if (ptr == NULL) {
        printf("Memory can not be allocated\n");
        exit(0);
    }

    else {
        printf("Memory allocated!\n");
        *ptr = 1;
        printf("All values set to %f\n", *ptr);
    }
    free(ptr);
    printf("Memory freed!\n");

}

void eighth_return() {

    printf("Running eighth function!\n");
    char* ptr = (char*)malloc(sizeof(char));

    if (ptr == NULL) {
        printf("Memory can not be allocated\n");
        exit(0);
    }

    else {
        printf("Memory allocated!\n");
        *ptr = 1;
        printf("All values set to %c\n", *ptr);
    }
    free(ptr);
    printf("Memory freed!\n");

}

void nineth_return() {

    printf("Running nineth function!\n");
    char r = 0, c = 0;
    printf("Enter an interger for the number of rows for the nineth function: ");
    fgets(&r, BUFF, stdin);
    printf("Enter an interger for the number of columns for the nineth function: ");
    fgets(&c, BUFF, stdin);

    char* ptr = (char*)malloc((r * c) * sizeof(char));

    if (ptr == NULL) {
        printf("Memory can not be allocated\n");
        exit(0);
    }

    else {
        printf("Memory allocated!\n");
        *ptr = 1;
        printf("All values set to %d\n", *ptr);
    }
    free(ptr);
    printf("Memory freed!\n");

}


void tenth_return() {

    printf("Running tenth function!\n");
    char input[BUFF];
    printf("Enter an interger for the size of the tenth function: ");
    fgets(input, BUFF, stdin);

    char* ptr = (char*)malloc(sizeof(input));

    if (ptr == NULL) {
        printf("Memory can not be allocated\n");
        exit(0);
    }

    else {
        printf("Memory allocated!\n");
        *ptr = 1;
        printf("All values set to %d\n", *ptr);
    }
    free(ptr);
    printf("Memory freed!\n");

}
