#ifndef VEHICLE_H_
#define VEHICLE_H_

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#ifndef BUF_SIZE
#define BUF_SIZE 64
#endif

typedef struct {
    int year;
    char *make;
    char *model;
    char *color;
    char *license_plate;
} vehicle_t;

vehicle_t *input_vehicle(vehicle_t *v);
vehicle_t **load_vehicles(char *filename, char **keys);
void print_vehicle(vehicle_t *v);

#endif
