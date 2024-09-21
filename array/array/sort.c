#include <stdio.h>

#define NMAX 10

int input_array(int *array);
void sotr_array(int *array);
void swap(int *a, int *b);
void output(const int *array);

int main() {
    int programm = 0;
    int data[NMAX];

    programm = input_array(data);
    if (programm != 0) {
        printf("n/a");
    } else {
        sotr_array(data);
        output(data);
    }

    return programm;
}

int input_array(int *array) {
    int programm = 0;

    for (int *p = array; p - array < NMAX; p++) {
        if (scanf("%d", p) != 1) {
            programm = 1;
        }
    }

    if (getchar() != '\n') {
        programm = 1;
    }

    return programm;
}

// Selection Sort - Сортировка по выбору 
void sotr_array(int *array) {
    for (int i = 0; i < NMAX; i++) {
        int min_element = i;
        for (int j = i + 1; j < NMAX; j++)
            if (array[j] < array[min_element]) min_element = j;
        swap(&array[min_element], &array[i]);
    }
}

void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

void output(const int *array) {
    for (int i = 0; i < NMAX; i++) {
        printf("%d ", array[i]);
    }
}
