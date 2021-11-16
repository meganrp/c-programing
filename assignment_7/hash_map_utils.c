#include "hash_map_utils.h"

int hash_function(char *key) {
    int hash = 0;

    for (int i = 0; i < strlen(key); i++) {
        hash += key[i];
    }

    return hash;
}

int compute_index(char *key, int map_size) {
    int hash = hash_function(key);
    int index = hash % map_size;

    return index;
}

double compute_load_factor(int num_keys, int bucket_size) {
    return (double)num_keys / bucket_size;
}

int matches_key(const void *elema, char *key) {
    hash_element_t *hash_elem = (hash_element_t *) elema;
    printf("[DEBUG] hash_map_utils.c::matches_key: hash_elem->key = %s, key = %s\n", hash_elem->key, key);
    return !strcmp(hash_elem->key, key);
}

/*
 * Initializes the map to a given `size`.
 */
void init_map(hash_map_t *map, int size) {
    map->primary = calloc(size, sizeof(void *));
    map->map_size = size;
    map->r_value = (int) ceil(1.0 / (DEFAULT_RESIZE_FACTOR - 1));
}

/*
 * Creates a new map to initiate incremental rehashing.
 */
void resize_map(hash_map_t *map, double factor) {
    map->temp = map->primary;
    map->temp_size = map->map_size;
    map->temp_index = 0;
    map->primary = calloc(map->map_size * (int) factor, sizeof(void *));
    map->map_size *= (int) factor;
    map->num_keys = 0;
    // TODO: Convert the r_value calculation into a macro
    map->r_value = (int) ceil(1.0 / (factor - 1));
}

/*
 * Searches a map that implements incremental rehashing.
 * It is necessary to check both the old and new maps
 * when searching for a key.
 *
 * Returns NULL if no such key was found.
 */
hash_element_t *search(hash_map_t *map, char *key) {
    if (map->temp != NULL) {
        int index = compute_index(key, map->temp_size);
        dynamic_array_t *elema = map->temp[index];

        if (elema == NULL) {
            return NULL;
        }

		// Search inside dynamic array to find the matching key
        return find_item(elema, key, matches_key);

    } else if (map->primary != NULL) {
        int index = compute_index(key, map->map_size);
        dynamic_array_t *elema = map->primary[index];

        printf("[DEBUG] hash_map_utils.c::search: elem = %p\n", elema);

        if (elema == NULL) {
            return NULL;
        }

		// Search inside dynamic array to find the matching key
        return find_item(elema, key, matches_key);
    }

    return NULL;
}

/*
 * Performs incremental rehashing on the map.
 */
void rehash_inc(hash_map_t *map) {
    for (int i = 0; i < map->r_value; i++) {
        // If there is nothing to rehash at the moment, return immediately.
        if (map->temp == NULL) {
            return;
        }

        // Iterate to next non-null value
        while (map->temp_index < map->temp_size && map->temp[map->temp_index] == NULL) {
            map->temp_index++;
        }

        // Check if temp map is empty
        if (map->temp_index == map->temp_size) {
            free(map->temp);
            map->temp = NULL;

            return;
        }

        hash_element_t *elema = pop_item(map->temp[map->temp_index], 0);
        int index = compute_index(elema->key, map->map_size);

        insert_item(&map->primary[index], elema);
        map->num_keys++;

        printf("[DEBUG] Rehashing %s into %d\n", elema->key, index);

        if (map->temp[map->temp_index]->size == 0) {
            free(map->temp[map->temp_index]);
            map->temp[map->temp_index] = NULL;
        }
    }
}

/*
 * Inserts an element into the map bucket, represented by a dynamic_array_t.
 */
void insert_item(dynamic_array_t **map, hash_element_t *elema) {
    if (*map == NULL) {
        *map = calloc(1, sizeof(dynamic_array_t));
    }

    array_insert(*map, elema, -1);
}

/*
 * Assumes that the element does not currently exist.
 */
void insert(hash_map_t *map, hash_element_t *elema) {
    int index = compute_index(elema->key, map->map_size);

    double factor = compute_load_factor(map->num_keys + 1, map->map_size);

    printf("[DEBUG] factor = %.2lf\n", factor);

    if (factor >= LOAD_FACTOR) {
        printf("[DEBUG] Beginning rehash...\n");
        // Begin rehash
        resize_map(map, DEFAULT_RESIZE_FACTOR);
    }

    printf("[DEBUG] Inserting %s at %d\n", elema->key, index);

    // TODO: Insert the item into the map at the calculated index
    insert_item(&map->primary[index], elema);
    map->num_keys++;

    rehash_inc(map);
}

