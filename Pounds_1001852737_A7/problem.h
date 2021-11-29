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

typedef struct {
    dynamic_array_t **temp;
    dynamic_array_t **primary;
    int num_keys;
    int temp_size;
    int map_size;
    int temp_index;
    int r_value;
} hash_map_t;

int matches_key(const void *elem, char *key);
void *find_item(dynamic_array_t *array, char *key, int (*check_fn)(const void *, char *));
hash_element_t *search(hash_map_t *map, char *key);
void print_map(dynamic_array_t **map, int array_size);
void search_map(dynamic_array_t **map, int array_size, char *input);
void print_array(dynamic_array_t *arr);
void insert_item(dynamic_array_t **map, hash_element_t *item);
void array_insert(dynamic_array_t *arr, hash_element_t *item);
int compute_index(char *key, int array_size);
int hash_function(char *key);

#endif