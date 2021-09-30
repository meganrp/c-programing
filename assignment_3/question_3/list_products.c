// C program for the above approach
#include <stdio.h>
#include <string.h>
#include "list_products.h"
  
  
// Driver Code
int main( int argc, char *argv[] )
{
     FILE* fp = NULL;

    if (argc == 2) {
      fp = fopen(argv[1], "r");
    }

    if (!fp) {
        printf("File not found!\n");
        return 0;
    }

    int length = 500;
    char csvBuffer[1024];
    int bit = 8;
        
    // Check file extension logic example 
    char *ext = strrchr(argv[1], '.');

    printf("Printing Extension: %s\n", ext);
    printf("Str compare: %d\n", strcmp(ext, ".dat")); 

    if (strcmp(ext, ".csv") == 0) {
        printf("CSV found!!!!\n");

        //fread(csvBuffer, bit, length, fp);
    

            // Here we have taken size of
        // array 1024 you can modify it
        int row = 0;
        int column = 0;

        while (fgets(csvBuffer, 1024, fp)) {
            row++;

            // To avoid printing of column
            // names in file can be changed
            // according to need
            if (row == 1)
                continue;

            // Splitting the data
            char* value = strtok(csvBuffer, ", ");

            if (column == 0) {
                printf("ID      Name                        Price       Qty\n");
                printf("-----------------------------------------------------\n");
            }

            while (value) {
                
                printf("%5s  ", value);
                value = strtok(NULL, ",");
                column++;
            }

            printf("\n");
        }

    }

    if (strcmp(ext, ".dat") == 0) {
        printf("Binary file found here!!\n"); 

        char check[4] = {'a', 'b', 'c', 'd'};
        char *fileType;
        //memset(check, 0, 4);
        fread(check, 4, 1, fp);
        printf("%c", check[0]);
        fileType = check;


        if (strcmp(fileType, 'CSEP') == 0) {
            printf("Something is wrong with the file!");

            return 0;
        }


    }
 

    // Close the file
    fclose(fp);
    
    return 0;
}