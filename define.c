/* Библиотеки */

#include <stdio.h>
#include <math.h>


/* Препроцессоры и макросы */

#define square(number) ((number) * (number)) // Макрос фукнции, возводящее чилос в квадрат
#define root(number) (pow(number, 0.5))
#define M_PI 3.14159265358979323846 // Препроцессор, заменяющий в коде M_PI на 3.14159265358979323846

/* Объявление функций */

// Функция, возращающая дискриминант квадратного уравнения
double discriminant(double a, double b, double c);
// Функция, находящая корни квадратного уравнения
void roots_equation(double a, double b, double c, double *one, double *two);


/* Главная функция */
int main()
{
    double one, two;

    roots_equation(1, 5, 6, &one, &two);
    printf("%.2f %.2f", one, two);

    return 0;
}


/* Определение функции */

// Функция, возращающая дискриминант квадратного уравнения
double discriminant(double a, double b, double c)
{
    double discriminant;
    discriminant = square(b) - 4 * a * c;

    return discriminant;
}

// Функция, находящая корни квадратного уравнения
void roots_equation(double a, double b, double c, double *one, double *two)
{
    double discriminants = discriminant(a, b, c);

    if (discriminants > 0) {
        *one = ((-b) + root(discriminants)) / (2 * a);
        *two = ((-b) - root(discriminants)) / (2 * a);
    } else if (discriminants == 0) {
        *one = ((-b) + root(discriminants)) / (2 * a);
    } else {
        *one = 0;
        *two = 0;
    }
}
