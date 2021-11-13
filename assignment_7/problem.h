#ifndef PROBLEM_H
#define PROBLEM_H

#define MAP_SIZE 10
#define BUF_SIZE 128

typedef struct {
    int year;
    char *make;
    char *model;
    char *color;
    char *license_plate;
} vehicle_t;

typedef struct {
    char *key;
    vehicle_t *value;
} hash_element_t;

typedef struct {
    int size;
    hash_element_t **data;
} dynamic_array_t;

void print_map(dynamic_array_t **map, int array_size);
void print_array(dynamic_array_t *arr);
void insert_item(dynamic_array_t **map, hash_element_t *item);
void array_insert(dynamic_array_t *arr, hash_element_t *item);
int compute_index(char *key, int array_size);
int hash_function(char *key);

#endif