#include "hash_map_utils.h"
#include "vehicle.h"

void print_array(dynamic_array_t *array) {
    for (int i = 0; i < array->size - 1; i++) {
        hash_element_t *elem = array->data[i];
        printf("%s, ", ((vehicle_t *)elem->value)->license_plate);
    }
    hash_element_t *elem = array->data[array->size - 1];
    printf("%s\n", ((vehicle_t *)elem->value)->license_plate);
}

void print_map(dynamic_array_t **map, int array_size) {
    for (int i = 0; i < array_size; i++) {
        printf("map[%d] = ", i);
        if (map[i] == NULL) {
            printf("EMPTY\n");
        } else {
            print_array(map[i]);
        }
    }
}

int main() {
    char buffer[BUF_SIZE] = { 0 };
    hash_map_t *map = calloc(1, sizeof(hash_map_t));
    init_map(map, 4);

    while (1) {
        printf("Enter a key: ");
        fgets(buffer, BUF_SIZE, stdin);
        buffer[strlen(buffer) - 1] = 0;

        hash_element_t *elem = search(map, buffer);

        if (elem != NULL) {
            printf("%s found!\n", buffer);
            print_vehicle(elem->value);
            continue;
        }

        // Copy the data to a hash_element_t
        elem = calloc(1, sizeof(hash_element_t));
        elem->key = malloc(sizeof(char) * (strlen(buffer) + 1));
        strcpy(elem->key, buffer);

        // Get value from the user
        vehicle_t *v = calloc(1, sizeof(vehicle_t));

        v->license_plate = calloc(strlen(elem->key) + 1, sizeof(char));
        strcpy(v->license_plate, elem->key);

        input_vehicle(v);

        elem->value = v;

        // Add element to the map
        insert(map, elem);
        print_map(map->primary, map->map_size);
    }

    return 0;
}

