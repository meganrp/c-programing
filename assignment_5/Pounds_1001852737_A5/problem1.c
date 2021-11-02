#include <stdio.h>
#include <string.h>
#include <stdlib.h> 
#include <ctype.h>
#include "problem1.h"


char* NormalizeString(char* string) {
    size_t len = strlen(string);
    char *stringNorm = calloc(len+1, sizeof(char));

    for (size_t i = 0; i < len; ++i) {
        stringNorm[i] = tolower((unsigned char) string[i]);
    }

    return stringNorm;
}

vehicle_t *read_vehicle(FILE *fp) {
    // begin cursor 
    long begin = 0;

    if (feof(fp)) {
        printf("\n Reached to the end of file.");
        return NULL;
    }

    // allocate memory for pointer
    vehicle_t *v = calloc(1, sizeof(vehicle_t)); 

    // read the size field 
    fread(&v->size, sizeof(long), 1, fp); 

    begin = ftell(fp);


    fread(&v->year, sizeof(int), 1, fp); 


    long string_start = ftell(fp); 
    while (fgetc(fp)); 
    long string_end = ftell(fp); 
    size_t makeSize = string_end - string_start;
    fseek(fp, string_start, SEEK_SET);
    v->make = calloc(makeSize, sizeof(char));
    fread(v->make, sizeof(char), makeSize, fp);

    // READ MODEL 
    string_start = ftell(fp); 
    while (fgetc(fp)); 
    string_end = ftell(fp); 
    size_t modelSize = string_end - string_start;
    fseek(fp, string_start, SEEK_SET);
    v->model = calloc(modelSize, sizeof(char));
    fread(v->model, sizeof(char), modelSize, fp);

    // READ COLOR 
    string_start = ftell(fp); 
    while (fgetc(fp)); 
    string_end = ftell(fp); 
    size_t colorSize = string_end - string_start;
    fseek(fp, string_start, SEEK_SET);
    v->color = calloc(colorSize, sizeof(char));
    fread(v->color, sizeof(char), colorSize, fp);

    // READ LICENSE PLATE 
    string_start = ftell(fp); 
    int string_size = v->size - (string_start - begin); 
    // You add one since we didn't read any null byte, the above while loops read the null byte and is used to 
    // allocate the proper memory size. 
    v->license_plate = calloc(string_size + 1, sizeof(char)); 
    fread(v->license_plate, sizeof(char), string_size, fp); 
    
    return v; 
}

vehicle_t *search_vehicle(FILE *fp, char* searchTerm) {
    if (feof(fp)) {
        printf("\n Reached to the end of file.");
        return NULL;
    }  

    // begin cursor 
    long begin = 0; 

    // allocate memory for  vehicle pointer
    vehicle_t *v = calloc(1, sizeof(vehicle_t)); 

    // read the size field 
    fread(&v->size, sizeof(long), 1, fp); 
    begin = ftell(fp);

    fread(&v->year, sizeof(int), 1, fp); 

    // Read Make 
    long string_start = ftell(fp); 
    while (fgetc(fp) && !feof(fp)); 
    long string_end = ftell(fp); 
    size_t makeSize = string_end - string_start;
    fseek(fp, string_start, SEEK_SET);
    v->make = calloc(makeSize, sizeof(char));
    fread(v->make, sizeof(char), makeSize, fp);

    // READ MODEL 
    string_start = ftell(fp); 
    while (fgetc(fp) && !feof(fp));  
    string_end = ftell(fp); 
    size_t modelSize = string_end - string_start;
    fseek(fp, string_start, SEEK_SET);
    v->model = calloc(modelSize, sizeof(char));
    fread(v->model, sizeof(char), modelSize, fp);

    // READ COLOR 
    string_start = ftell(fp); 
    while (fgetc(fp) && !feof(fp)); 
    string_end = ftell(fp); 
    size_t colorSize = string_end - string_start;
    fseek(fp, string_start, SEEK_SET);
    v->color = calloc(colorSize, sizeof(char));
    fread(v->color, sizeof(char), colorSize, fp);

    // READ LICENSE PLATE 
    string_start = ftell(fp); 
    int string_size = v->size - (string_start - begin); 
    v->license_plate = calloc(string_size + 1, sizeof(char)); 
    fread(v->license_plate, sizeof(char), string_size, fp); 

    // NORMALIZATION
    char* searchNorm = NormalizeString(searchTerm);
    char* makeNorm = NormalizeString(v->make);
    char* modelNorm = NormalizeString(v->model);
    char* colorNorm = NormalizeString(v->color); 

    // Check each string 
    if (strcmp(makeNorm, searchNorm) == 0) {
        return v; 
    }
    
    if (strcmp(modelNorm, searchNorm) == 0) {
        return v; 
    }

    if (strcmp(colorNorm, searchNorm) == 0) {
        return v; 
    }
    free(searchNorm);
    free(makeNorm);
    free(modelNorm);
    free(colorNorm);

    return NULL; 
}

void print_vehicle(vehicle_t *v) {
    if (v == NULL) {
        return; 
    }

    printf("%d %s %s %s LIC#%s\n", v->year, v->make, v->model, v->color, v->license_plate);

}


int main(int argc, char *argv[]) {
    FILE *fp = fopen("vehicles.db", "rb"); 
    char* search = NULL;

    if (argc == 3) {
      fp = fopen(argv[1], "r");
      if (!fp) {
        printf("File not found!\n");
        return 0;
        }

       search = argv[2];
    } else {
        printf("Invalid length of arguments.");
        return 0;
    }

    
    vehicle_t *v1 = NULL; 
    

    // while (1) {
    //     v1 = search_vehicle(fp, search);
    //     print_vehicle(v1);

    //     if (feof(fp)){
    //         break;
    //     }
    // }

    for(int i = 0; i<14; i++) {
        v1 = search_vehicle(fp, search);
        print_vehicle(v1);
        
        if (feof(fp)){
            break;
        }
    }

    fclose(fp);
    free(v1);
    printf("End of program.\n");

    return 0;
}