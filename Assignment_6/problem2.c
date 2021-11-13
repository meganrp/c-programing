#include "problem2.h"

#define max 20
#define MAX_LINE_LENGTH 80

int space = 0;
int top = -1; 


void print_with_indent(int indent, char * string)
{
    printf("%*s%s", indent, "", string);
}


void push(char* stack, char data[80])
{
      if(top == max -1) {
          printf("Stack is full! \n"); 
      }
      else
      {
            top = top + 1;
            strcpy(&stack[top], data);
            print_with_indent(space, &stack[top]);
            space += 3;
      }
}


void pop(char* stack, char data[80])
{
      if(top == -1)
            printf("Stack is empty!"); 
      else
      { 
            strcpy(data, &stack[top]);
            top = top - 1;
            space -= 3;
      }
}


int main(int argc, char **argv)
{
    // char stack[max][80], nm[80];
    // int top, reply;
    // top = -1;   // Initialize Stack

    char* stack = (char*) malloc((MAX_LINE_LENGTH) * sizeof(char)); 
    

    char *path;
    char line[MAX_LINE_LENGTH] = {0};
    
    if (argc < 2) {
        printf("No file argument was passed. \n");
        return 1;
    }

    path = argv[1];
    
    /* Open file */
    FILE *file = fopen(path, "r");
    
    if (!file)
    {
        printf("Could not read file. \n");
        return 1;
    }
    
    /* Get each line until there are none left */
    while (fgets(line, MAX_LINE_LENGTH, file))
    {   
        /* Print each line */
        
        char *checkFunc;
        checkFunc = strstr(line, "()");
        if (checkFunc) {
            // print_with_indent(space, stack[top]);
            
            push(stack, line);
            // printf("Found a function!\n");
            
        }

        char *checkReturn; 
        checkReturn = strstr(line, "return");
        if (checkReturn) {
            // printf("Found a return!\n");
            pop(stack, line);
            
        }
    }
    
    /* Close file */
    if (fclose(file))
    {
        return EXIT_FAILURE;
        perror(path);
    }

    free(stack);

    return 0;
}