#include <stdio.h>

// Нахождение объема параллелепипеда
double volume_parallelepiped(double a, double b, double c) {
    double volume = a * b * c;
    return volume;
}

int main() {
    double a, b, c;

    a = b = 10.0;
    c = 23.6;

    double volume = volume_parallelepiped(a, b, c);
    printf("%f", volume);

    return 0;
}
