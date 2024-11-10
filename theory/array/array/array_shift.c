#include <stdio.h>

#define NMAX 10

int input_array(int *array, int *n);
void output_array(const int *array, int n);
int input_shift(int *shift);
void shift_element(int *array, int n, int shift);

int main() {
    int programm = 0;
    int n, data[NMAX];

    programm = input_array(data, &n);

    if (programm != 0) {
        printf("n/a");
    } else {
        int shift;
        int shift_programm = input_shift(&shift);

        if (shift_programm != 0) {
            printf("n/a");
            programm = 1;
        } else {
            shift_element(data, n, shift);
            output_array(data, n);
        }
    }

    return programm;
}

int input_array(int *array, int *n) {
    int programm = 0;

    if (scanf("%d", n) != 1 || getchar() != '\n' || *n > NMAX || *n <= 0) {
        programm = 1;
    } else {
        for (int *p = array; p - array < *n; p++) {
            if (scanf("%d", p) != 1) {
                programm = 1;
            }
        }

        if (getchar() != '\n') {
            programm = 1;
        }
    }

    return programm;
}

void output_array(const int *array, int n) {
    for (int i = 0; i < n; i++) {
        printf("%d ", array[i]);
    }
}

int input_shift(int *shift) {
    int programm = 0;

    if (scanf("%d", shift) != 1 || getchar() != '\n') {
        programm = 1;
    }

    return programm;
}

void shift_element(int *array, int n, int shift) {
    // shift отрицательный -> свдиг по массиву происходит вправо
    if (shift < 0) {
        for (int j = 0; j < -shift; j++) {
            int temp = array[n - 1];

            for (int i = n - 1; i > 0; i--) {
                array[i] = array[i - 1];
            }

            array[0] = temp;
        }
    } else {
        // shift положительный -> свдиг по массиву происходит влево
        for (int j = 0; j < shift; j++) {
            int temp = array[0];

            for (int i = 0; i < n - 1; i++) {
                array[i] = array[i + 1];
            }

            array[n - 1] = temp;
        }
    }
}
