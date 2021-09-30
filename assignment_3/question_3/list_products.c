#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "list_products.h"
  
  
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

    char csvBuffer[1024];
        
    // Check file extension logic example 
    char *ext = strrchr(argv[1], '.');

    printf("Printing Extension: %s\n", ext);
    printf("Str compare: %d\n", strcmp(ext, ".dat")); 

    

    if (strcmp(ext, ".csv") == 0) {
        printf("CSV found!!!!\n");

        int row = 0;
        int column = 0;

        while (fgets(csvBuffer, 1024, fp)) {
            row++;

            if (row == 1)
                continue;

            // Splitting the data
            char* value = strtok(csvBuffer, ", ");

            if (column == 0) {
                printf("ID      Name                        Price       Qty\n");
                printf("-----------------------------------------------------\n");
            }

            while (value) {
                
                printf("%8s  ", value);
                value = strtok(NULL, ",");
                column++;
            }

            printf("\n");
        }

    }
    

    if (strcmp(ext, ".dat") == 0) {
        printf("Binary file found here!!\n"); 

        struct t_product *products = calloc(1, sizeof( struct t_product));
    
        fread(&products->ID, sizeof(int), 1, fp);
        fread(&products->Name, sizeof(char[128]), 1, fp);
        fread(&products->Price, sizeof(double), 1, fp);
        fread(&products->Quantity, sizeof(int), 1, fp);

        struct t_product *p = products;
        printf("ID: %d\n", p->ID);
        printf("Name: %s\n", p->Name);
        printf("Price: %.2lf\n", p->Price);
        printf("Quantity: %d\n", p->Quantity);

        free(p);

    }
 

    // Close the file
    fclose(fp);
    
    return 0;
    
}