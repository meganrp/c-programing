#include <stdio.h>
#include <stdlib.h>

void f() {
    double **arr = calloc(100, sizeof(void *));

    for (int i = 0; i < 100; i++) {
        arr[i] = calloc(50, sizeof(double));
        for (int j = 0; j < 50; j++) {
        arr[i][j] = i + j + 1;
        }
    }

    free(arr);
    free(*arr);
}

int main() {
    f();
    return 0;
}