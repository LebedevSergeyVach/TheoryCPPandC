/* Библиотеки */

#include <stdio.h>
#include <math.h>

/* Препроцессоры и макросы */

#define square(number) ((number) * (number)) // Макрос фукнции, возводящей чилос в квадрат
#define root(number) (pow(number, 0.5))      // Макрос функции, находящей корень числа

#define M_PI 3.14159265358979323846 // Препроцессор, заменяющий в коде M_PI на 3.14159265358979323846

/* Объявление функций */

// Функция, возращающая дискриминант квадратного уравнения
double discriminant(double a, double b, double c);
// Функция, находящая корни квадратного уравнения
void roots_equation(double a, double b, double c, double *one, double *two);
// Функция, переводящщая минуты в электронный циферблат (mm) -> (hh:mm)
void min2time(int mm, int *ph, int *pm);

/* Главная функция */
int main()
{
    double a, b, c, one, two;

    printf("Enter the arguments of the quadratic equation in the format (a b c): "); // 1 5 6
    scanf("%lf%lf%lf", &a, &b, &c);
    roots_equation(a, b, c, &one, &two);
    printf("The first root of the quadratic equation (%.2fx^2 + %.2fx + %.2f) = %.2f, the second root = %.2f\n", a, b, c, one, two);

    int mm, h, m;

    printf("Enter the minutes to display on the dial: "); // 1440
    scanf("%d", &mm);
    min2time(mm, &h, &m);
    printf("TIME %02d:%02d\n", h, m);

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

    if (discriminants > 0)
    {
        *one = ((-b) + root(discriminants)) / (2 * a);
        *two = ((-b) - root(discriminants)) / (2 * a);
    }
    else if (discriminants == 0)
    {
        *one = ((-b) + root(discriminants)) / (2 * a);
    }
    else
    {
        *one = 0;
        *two = 0;
    }
}

// Функция, переводящщая минуты в электронный циферблат (mm) -> (hh:mm)
void min2time(int mm, int *ph, int *pm)
{
    mm %= 1440;
    *ph = mm / 60;
    *pm = mm - *ph * 60;
}
