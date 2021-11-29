#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "problem.h"

// Macro format
#define resize (R) ((R+1)/R)
#define DEBUG(x) do { std::cerr << x; } while (0)


int main() {

    char buffer[BUF_SIZE] = { 0 };
    dynamic_array_t **map = calloc(10, sizeof(void *));
    int input = 0;

    while(1) {

        printf("1. Add Vehicle\n2. Import File\n3. Vehicle Lookup\n4. Print Map\n> ");
        scanf("%d", &input);

        switch (input) {

            case 1:
                printf("(key = lisense plate)\nEnter a key: ");
                getchar(); 
                fgets(buffer, BUF_SIZE, stdin);
                buffer[strlen(buffer) - 1] = 0;
                
                // Copy the data to a hash_element_t
                hash_element_t *elem = calloc(1, sizeof(hash_element_t));
                elem->key = malloc(sizeof(char) * (strlen(buffer) + 1));
                strcpy(elem->key, buffer);

                // Convert the key to an index
                int index = compute_index(elem->key, MAP_SIZE);

                // Check for collisions
                if (map[index] != NULL) {
                    printf("COLLISION DETECTED\n");
                }

                // Get value from the user
                elem->value = calloc(1, sizeof(vehicle_t));

                printf("Enter a year: ");
                scanf("%d", &elem->value->year);
                while (getchar() != '\n');

                printf("Enter a make: ");
                fgets(buffer, BUF_SIZE, stdin);
                buffer[strlen(buffer) - 1] = 0;
                elem->value->make = calloc(strlen(buffer) + 1, sizeof(char));
                strcpy(elem->value->make, buffer);

                printf("Enter a model: ");
                fgets(buffer, BUF_SIZE, stdin);
                buffer[strlen(buffer) - 1] = 0;
                elem->value->model = calloc(strlen(buffer) + 1, sizeof(char));
                strcpy(elem->value->model, buffer);

                printf("Enter a color: ");
                fgets(buffer, BUF_SIZE, stdin);
                buffer[strlen(buffer) - 1] = 0;
                elem->value->color = calloc(strlen(buffer) + 1, sizeof(char));
                strcpy(elem->value->color, buffer);
                elem->value->license_plate = calloc(strlen(elem->key) + 1, sizeof(char));
                strcpy(elem->value->license_plate, elem->key);

                // Add element to the map
                insert_item(&map[index], elem);
                print_map(map, MAP_SIZE);

                break;

            case 2:
                break;

            case 3:
                printf("Enter key you want to search: ");
                getchar();
                fgets(buffer, BUF_SIZE, stdin);
                buffer[strlen(buffer) - 1] = 0;
                search_map(map, MAP_SIZE, buffer);
                break;                  

            case 4:
                print_map(map, MAP_SIZE);
                break;
            
            default:
                printf("Invalid input, please learn how to read\n");
                return 0;



        }
    }

}

int matches_key(const void *elem, char *key) {
    hash_element_t *hash_elem = (hash_element_t *) elem;
    printf("[DEBUG] hash_map_utils.c::matches_key: hash_elem->key = %s, key = %s\n", hash_elem->key, key);
    return !strcmp(hash_elem->key, key);
}

void print_map(dynamic_array_t **map, int array_size) {
    for (int i = 0; i < array_size; i++) {
        printf("map[%d] = ", i);
        if (map[i] != NULL) {
            print_array(map[i]);
        } else {
            printf("EMPTY\n");
        }
    }
}


hash_element_t *search(hash_map_t *map, char *key) {
    if (map->temp != NULL) {
        int index = compute_index(key, map->temp_size);
        dynamic_array_t *elem = map->temp[index];

        if (elem == NULL) {
            return NULL;
        }

		// Search inside dynamic array to find the matching key
        return find_item(elem, key, matches_key);

    } else if (map->primary != NULL) {
        int index = compute_index(key, map->map_size);
        dynamic_array_t *elem = map->primary[index];

        printf("[DEBUG] hash_map_utils.c::search: elem = %p\n", elem);

        if (elem == NULL) {
            return NULL;
        }

		// Search inside dynamic array to find the matching key
        return find_item(elem, key, matches_key);
    }

    return NULL;
}

int hash_function(char *key) {
    printf("key: %s\n", key);
    int hash = 0;
    //Summation??
    for (int i = 0; i < strlen(key); i++) {
        hash += key[i];
    }
    printf("hash: %d\n", hash);
    return hash;
}

int compute_index(char *key, int array_size) {
    int hash = hash_function(key);
    int index = hash % array_size;
    printf("index: %d\n", index);
    return index;
}

void *find_item(dynamic_array_t *array, char *key, int (*check_fn)(const void *, char *)) {
    for (int i = 0; i < array->size; i++) {
        // Taking advantage of the fact that `key` is the first member of the struct
        if (check_fn(array->data[i], key)) {
            printf("[DEBUG] dynamic_arrays.c::find_item: Found item %s\n", key);
            return array->data[i];
        }
    }

    return NULL;
}

void array_insert(dynamic_array_t *arr, hash_element_t *item) {
    arr->data = realloc(arr->data, (arr->size + 1) * sizeof(void *));
    arr->data[arr->size] = item;
    arr->size++;
}

void insert_item(dynamic_array_t **map, hash_element_t *item) {
    // If map is empty (initial state), then allocate some memory
    if (*map == NULL) {
        *map = calloc(1, sizeof(dynamic_array_t));
    }
    array_insert(*map, item);
}

void print_array(dynamic_array_t *arr) {
    vehicle_t *temp = NULL;
    for (int i = 0; i <= arr->size - 1; i++) {
        temp = arr->data[i]->value;
        printf("{%s, %d, %s}, ", temp->license_plate, temp->year, temp->make);
    }
}

void search_map(dynamic_array_t **map, int array_size, char *input) {
    printf("Input: %s\n", input);

    for (int i = 0; i < array_size; i++) {
        printf("map[%d] = ", i);

        if (map[i] != NULL) {
            vehicle_t *temp = NULL;

            for (int j = 0; j < map[i]->size - 1; j++) {
                temp = map[i]->data[j]->value;
                printf("{%s, %d, %s}, ", temp->license_plate, temp->year, temp->make);
                
                if(strcmp(input, temp->license_plate) == 0) {
                    printf("Found a fuckin match ya'll\n");
                }
            }
            print_array(map[i]);

        } else {
            printf("EMPTY\n");
        }
    }
}