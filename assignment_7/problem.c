#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "problem.h"

// Macro format
#define resize (R) ((R+1)/R)


int main() {

    char buffer[BUF_SIZE] = { 0 };
    dynamic_array_t **map = calloc(10, sizeof(void *));
    int input = 0;

    while(1) {

        printf("1. Add Vehicle\n2. Import File\n3. Vehicle Lookup\n4. Print Map\n(key = lisense plate)\n> ");
        scanf("%d", &input);

        switch (input) {

            case 1:
                printf("Enter a key: ");
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
    for (int i = 0; i < arr->size - 1; i++) {
        temp = arr->data[i]->value;
        printf("{%s, %d, %s}, ", temp->license_plate, temp->year, temp->make);
    }
    temp = arr->data[arr->size - 1]->value;
    printf("{%s, %d, %s}\n", temp->license_plate, temp->year, temp->make);
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
