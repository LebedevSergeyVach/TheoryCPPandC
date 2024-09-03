#include "data_stat.h"

#include <stdlib.h>

double max(double *data, int n);
double min(double *data, int n);
double mean(double *data, int n);
double variance(double *data, int n);
void sort(double *array, int n);
void swap(double *a, double *b);

double max(double *data, int n) {
    double max = data[0];

    for (int i = 0; i < n; i++) {
        if (max < data[i]) {
            max = data[i];
        }
    }

    return max;
}

double min(double *data, int n) {
    double min = data[0];

    for (int i = 0; i < n; i++) {
        if (min > data[i]) {
            min = data[i];
        }
    }

    return min;
}

double mean(double *data, int n) {
    double sum = 0.0;

    for (int i = 0; i < n; i++) {
        sum += data[i];
    }

    return sum / n;
}

double variance(double *data, int n) {
    double variance = 0.0;
    double sum = 0.0;

    for (int i = 0; i < n; i++) {
        sum += data[i] * data[i];
    }

    variance = sum / n - (mean(data, n) * mean(data, n));

    return variance;
}

// Selection Sort - Сортировка по выбору 
void sort(double *array, int n) {
    for (int i = 0; i < n; i++) {
        int min_element = i;
        for (int j = i + 1; j < n; j++)
            if (array[j] < array[min_element]) min_element = j;
        swap(&array[min_element], &array[i]);
    }
}

void swap(double *a, double *b) {
    double temp = *a;
    *a = *b;
    *b = temp;
}
