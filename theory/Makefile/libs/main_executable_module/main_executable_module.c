#include <stdio.h>
#include <stdlib.h>

#include "../data_libs/data_io.h"
#include "../data_libs/data_stat.h"
#include "../data_module/data_process.h"
#include "../yet_another_decision_module/decision.h"

int main() {
    int programm = 0;
    int n;

    printf("LOAD DATA...\n");

    if (scanf("%d", &n) != 1 || getchar() != '\n') {
        programm = 1;
    } else {
        double *data = malloc(n * sizeof(double));

        if (input(data, n) != 0) {
            programm = 1;
        } else {
            printf("RAW DATA:\n\t");
            output(data, n);

            printf("\nNORMALIZED DATA:\n\t");
            normalization(data, n);
            output(data, n);

            printf("\nSORTED NORMALIZED DATA:\n\t");
            sort(data, n);
            output(data, n);

            printf("\nFINAL DECISION:\n\t");
            if (make_decision(data, n))
                printf("YES");
            else
                printf("NO");
        }

        free(data);
    }

    if (programm != 0) {
        printf("n/a");
    }

    return programm;
}
