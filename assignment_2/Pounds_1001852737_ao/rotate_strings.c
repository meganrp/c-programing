#include <stdio.h>
#include <string.h>

#define ARRAY_SIZE 128
#define MAX_INPUT 4

void RotateStrings(char *input[MAX_INPUT], int numToRotate, int total);


int main() {

    //get user input
    //char input[MAX_INPUT][ARRAY_SIZE];
    int rotation;
    int i, counter = 0;
    char input1[ARRAY_SIZE], input2[ARRAY_SIZE], input3[ARRAY_SIZE], input4[ARRAY_SIZE];


    while(1) {

        printf("Enter a string: ");
        fgets(input1, ARRAY_SIZE, stdin);

   
            if(strlen(input1) == 1) {
            printf("Empty string encountered!\n");

            break;
            }
        
        counter++;
         printf("Enter a string: ");
        fgets(input2, ARRAY_SIZE, stdin);

            
            if(strlen(input2) == 1) {
            printf("Empty string encountered!\n");

            break;
            }
        counter++;
         printf("Enter a string: ");
        fgets(input3, ARRAY_SIZE, stdin);

            
            if(strlen(input3) == 1) {
            printf("Empty string encountered!\n");

            break;
            }
        counter++;
         printf("Enter a string: ");
        fgets(input4, ARRAY_SIZE, stdin);

            
            if(strlen(input4) == 1) {
            printf("Empty string encountered!\n");

            break;
            }
        counter++;
        break; 
    }

    printf("Enter a number: ");
    scanf("%d", &rotation);

    char *inputPtr[MAX_INPUT];
    
    if(counter >= 1) {
        inputPtr[0] = input1;
    }

    if(counter >= 2) {
        inputPtr[1] = input2;
    }

    if(counter >= 3) {
        inputPtr[2] = input3;
    }

    if(counter >= 4) {
        inputPtr[3] = input4;
    }


    printf("Number of elements: %d\n", counter);

    // Access data 
    for(i = 0; i < counter; i++) {

        printf("Input Pointer: \n"); 
        printf("%s", inputPtr[i]); 
    }

    // printf("%d strings read.", NumOfElements); 

    //Function call 
    RotateStrings(inputPtr, rotation, counter);


    //Print final order
    for(i = 0; i < counter; i++) {
        printf("%s\n", inputPtr[i]);
    }
    
    return 0;
}

void RotateStrings(char *input[MAX_INPUT], int numToRotate, int total) { 

        //Rotate the given array by n times toward right    
    for(int i = 0; i < numToRotate; i++) {    
        int last;    
        //Stores the last element of the array    
        last = *input[total-1];    

        input[i+1] = input[i];
        
        //Last element of array will be added to the start of array.    
        *input[0] = last;   
    }

}