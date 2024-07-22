#include <stdio.h>
#include <math.h> // gcc -o main main.c -lm

/* Объявление функций */

// Нахождение объема параллелепипеда
double volume_parallelepiped(double a, double b, double c);
// Нахождение площади круга
double area_circle(double radius);
// Нахождение объема цилиндра
double volume_cylinder(double radius, double height);
// Нахождение объема шара
double volume_ball(double radius);
// Нахождение объема конуса
double volume_cone(double radius, double height);

/* Главная функция */
int main()
{
    double radius, height, cylinder, ball, cone;
    radius = 5.0;
    height = 12.0;

    cylinder = volume_cylinder(radius, height);
    ball = volume_ball(radius);
    cone = volume_cone(radius, height);

    printf("Volume cylinder = %f\n", cylinder);
    printf("Volume ball = %f\n", ball);
    printf("Volume cone = %f\n", cone);

    return 0;
}

/* Определение функции */

// Нахождение объема параллелепипеда
double volume_parallelepiped(double a, double b, double c) 
{
    double volume;
    volume = a * b * c;

    return volume;
}

// Нахождение площади круга
double area_circle(double radius) 
{
    double area;
    area = M_PI * pow(radius, 2);

    return area;
}

// Нахождение объема цилиндра
double volume_cylinder(double radius, double height)
{
    double volume;
    double area;

    area = area_circle(radius);
    volume = M_PI * height * pow(area, 2);

    return volume;
}

// Нахождение объема шара
double volume_ball(double radius)
{
    double volume;
    volume = 4 / 3 * M_PI * pow(radius, 3);

    return volume;
}

// Нахождение объема конуса
double volume_cone(double radius, double height)
{
    double volume;
    double area;

    area = area_circle(radius);
    volume = area * height / 3;

    return volume;
}
