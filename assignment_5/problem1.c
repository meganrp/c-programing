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

    // allocate memory for pointer
    vehicle_t *v = calloc(1, sizeof(vehicle_t)); 

    // read the size field 
    fread(&v->size, sizeof(long), 1, fp); 

    // this is the file offset of when the data actually starts after size 
    // This is used to calculate the memory size for license plate which doesn't 
    // have a null byte at the end. 
    begin = ftell(fp);

    fread(&v->year, sizeof(int), 1, fp); 

    // READ MAKE 
    // This stores the beginning position of the start of our first string
    // We know this due to how the struct is laid out. 
    long string_start = ftell(fp); 
    // Stupid magic of catching the null byte terminator
    while (fgetc(fp)); 
    // Once we reached the null terminator we store the current cursor position for the string's end
    long string_end = ftell(fp); 
    // Size of make string is determined by subtracting the end pos with the start pos
    size_t makeSize = string_end - string_start;
    // Rewind back to the start of the string to prepare for reading the data. 1st part was just to figure out the size for mem allocation.
    fseek(fp, string_start, SEEK_SET);
    // Allocate enough memory to struct field since we now know its size. 
    v->make = calloc(makeSize, sizeof(char));
    // Now that memory is allocated, THEN we can read into the field. ALWAYS ALLOCATE MEMORY FIRST FOR POINTERS!
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
    vehicle_t *v = calloc(1, sizeof(vehicle_t) * 10); 

    // printf("reading size... \n");
    // read the size field 
    fread(&v->size, sizeof(long), 1, fp); 
    // this is the file offset of when the data actually starts after size 
    // This is used to calculate the memory size for license plate which doesn't 
    // have a null byte at the end. 
    begin = ftell(fp);

    // printf("reading year... \n");
    fread(&v->year, sizeof(int), 1, fp); 

    // Read Make 
    // printf("reading make... \n");
    long string_start = ftell(fp); 
    while (fgetc(fp) && !feof(fp)); 
    long string_end = ftell(fp); 
    size_t makeSize = string_end - string_start;
    fseek(fp, string_start, SEEK_SET);
    v->make = calloc(makeSize, sizeof(char));
    fread(v->make, sizeof(char), makeSize, fp);

    // READ MODEL 
    // printf("reading model... \n");
    string_start = ftell(fp); 
    while (fgetc(fp) && !feof(fp));  
    string_end = ftell(fp); 
    size_t modelSize = string_end - string_start;
    fseek(fp, string_start, SEEK_SET);
    v->model = calloc(modelSize, sizeof(char));
    fread(v->model, sizeof(char), modelSize, fp);

    // READ COLOR 
    // printf("reading color... \n");
    string_start = ftell(fp); 
    while (fgetc(fp) && !feof(fp)); 
    string_end = ftell(fp); 
    size_t colorSize = string_end - string_start;
    fseek(fp, string_start, SEEK_SET);
    v->color = calloc(colorSize, sizeof(char));
    fread(v->color, sizeof(char), colorSize, fp);

    // READ LICENSE PLATE 
    // printf("reading license... \n");
    string_start = ftell(fp); 
    int string_size = v->size - (string_start - begin); 
    // You add one since we didn't read any null byte, the above while loops read the null byte and is used to 
    // allocate the proper memory size. 
    v->license_plate = calloc(string_size + 1, sizeof(char)); 
    fread(v->license_plate, sizeof(char), string_size, fp); 

    // Now that we read the entire vehicle, we can check whether or not any of the strings match. 
    // Also, we need to normalize the vehicle strings by lowercasting them for search accuracy. 

    // NORMALIZATION
    char* searchNorm = NormalizeString(searchTerm);
    char* makeNorm = NormalizeString(v->make);
    char* modelNorm = NormalizeString(v->model);
    char* colorNorm = NormalizeString(v->color); 

   
    // printf("Comparing each string...\n\n");
    // Check each string 
    if (strcmp(makeNorm, searchNorm) == 0) {
        // printf("Found match MAKE!\n");
        return v; 
    }
    
    if (strcmp(modelNorm, searchNorm) == 0) {
        // printf("Found match MODEL!\n");
        return v; 
    }

    if (strcmp(colorNorm, searchNorm) == 0) {
        // printf("Found match COLOR!\n");
        return v; 
    }

    // free up the memory
    free(searchNorm);
    free(makeNorm);
    free(modelNorm);
    free(colorNorm);

    // Return nothing if there weren't any matches. RIP
    return NULL; 
}

void print_vehicle(vehicle_t *v) {
    if (v == NULL)
        return; 

    printf("%d %s %s %s LIC#%s\n", v->year, v->make, v->model, v->color, v->license_plate);

    // printf("Size: %ld\n", v->size); 
    // printf("Year: %d\n", v->year); 
    // printf("Make: %s\n", v->make); 
    // printf("Model: %s\n", v->model); 
    // printf("Color: %s\n", v->color); 
    // printf("License: %s\n\n", v->license_plate); 
}


int main(int argc, char *argv[]) {
    // Open file, create file pointer
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

    
    // Call read vehicle function, returns populated data.
    // vehicle_t *v1 = read_vehicle(fp); 
    // vehicle_t *v2 = read_vehicle(fp); 
    // vehicle_t *v3 = read_vehicle(fp); 
    // vehicle_t *v4 = read_vehicle(fp); 
    // vehicle_t *v5 = read_vehicle(fp); 
    // vehicle_t *v6 = read_vehicle(fp); 

    // print_vehicle(v1); 
    // print_vehicle(v2); 
    // print_vehicle(v3); 
    // print_vehicle(v4); 
    // print_vehicle(v5); 
    // print_vehicle(v6); 

    
    vehicle_t *v1 = NULL; 

    // I HATE MYSELF FOR THIS SECTION BUT I CAN'T FIGURE OUT HOW TO PROPERLY CHECK EOF WITH A LOOP. 
    // Just getting frustrated, so going with this monstrosity.
    // CHECK MY FIRST BRANCH. 
    v1 = search_vehicle(fp, search);
    print_vehicle(v1);

    v1 = search_vehicle(fp, search);
    print_vehicle(v1);

    v1 = search_vehicle(fp, search);
    print_vehicle(v1);

    v1 = search_vehicle(fp, search);
    print_vehicle(v1);

    v1 = search_vehicle(fp, search);
    print_vehicle(v1);

    v1 = search_vehicle(fp, search);
    print_vehicle(v1);

    v1 = search_vehicle(fp, search);
    print_vehicle(v1);

    v1 = search_vehicle(fp, search);
    print_vehicle(v1);

    v1 = search_vehicle(fp, search);
    print_vehicle(v1);

    v1 = search_vehicle(fp, search);
    print_vehicle(v1);


    fclose(fp);
    free(v1);
    printf("End of program.\n");

    return 0;
}