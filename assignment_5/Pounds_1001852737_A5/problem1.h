#ifndef VEHICLES_H
#define VEHICLES_H

typedef struct {
    long size;
    int year; 
    char *make; 
    char *model; 
    char *color; 
    char *license_plate; 
} vehicle_t;

char* NormalizeString(char* string);
vehicle_t *read_vehicle(FILE *fp);
vehicle_t *search_vehicle(FILE *fp, char* searchTerm);
void print_vehicle(vehicle_t *v);

#endif 