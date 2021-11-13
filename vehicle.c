#include "vehicle.h"


/*
 * Reads in vehicle data for a single vehicle form the user.
 * If the input vehicle is NOT NULL, only the NON-NULL entries
 * will be requested from the user.
 */
vehicle_t *input_vehicle(vehicle_t *v) {
    char buffer[BUF_SIZE] = { 0 };

    if (v == NULL) {
        v = calloc(1, sizeof(vehicle_t));
    }

    if (v->year == 0) {
        printf("Enter year: ");
        scanf("%d", &v->year);
        while (getchar() != '\n');
    }

    if (v->make == NULL) {
        printf("Enter make: ");
        fgets(buffer, BUF_SIZE, stdin);
        buffer[strlen(buffer) - 1] = 0;
        v->make = calloc(strlen(buffer) + 1, sizeof(char));
        strcpy(v->make, buffer);
    }

    if (v->model == NULL) {
        printf("Enter model: ");
        fgets(buffer, BUF_SIZE, stdin);
        buffer[strlen(buffer) - 1] = 0;
        v->model = calloc(strlen(buffer) + 1, sizeof(char));
        strcpy(v->model, buffer);
    }

    if (v->color == NULL) {
        printf("Enter color: ");
        fgets(buffer, BUF_SIZE, stdin);
        buffer[strlen(buffer) - 1] = 0;
        v->color = calloc(strlen(buffer) + 1, sizeof(char));
        strcpy(v->color, buffer);
    }

    if (v->license_plate == NULL) {
        printf("Enter license plate: ");
        fgets(buffer, BUF_SIZE, stdin);
        buffer[strlen(buffer) - 1] = 0;
        v->license_plate = calloc(strlen(buffer) + 1, sizeof(char));
        strcpy(v->license_plate, buffer);
    }

    return v;
}

/*
 * Loads vehicles from a file.
 * If `keys` is NOT NULL, this function will not save any vehicle
 * that has a key in `keys`.
 */
vehicle_t **load_vehicles(char *filename, char **keys) {
    // TODO: Implement function
    return NULL;
}

void print_vehicle(vehicle_t *v) {
    printf("%d %s %s (%s) LIC#%s\n", v->year, v->make, v->model, v->color, v->license_plate);
}
