#include <stdio.h>
#include <stdlib.h>

#include "../data_libs/data_io.h"
#include "data_process.h"

int main() {
    int programm = 0;
    int n;

    if (scanf("%d", &n) != 1 || getchar() != '\n') {
        programm = 1;
    } else {
        double *data = malloc(n * sizeof(double));

        if (input(data, n) != 0) {
            programm = 1;
        } else {
            if (normalization(data, n))
                output(data, n);
            else
                printf("ERROR");
        }

        free(data);
    }

    if (programm != 0) {
        printf("n/a");
    }

    return programm;
}
