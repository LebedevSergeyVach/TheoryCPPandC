#include <stdio.h>
#include <string.h>

/* Переменные и типы данных -> int double float ... */
int main()
{
    // int
    int ints = 25;
    printf("int: %d\n", ints);

    // float
    float floats = 5.9;
    printf("float: %.2f\n", floats);

    // double
    double doubles = 2.71828;
    printf("double: %lf\n", doubles);

    // long double
    long double long_double = 1.414213562373095048L;
    printf("long double: %Lf\n", long_double);

    // char
    char chars = 'J';
    printf("char: %c\n", chars);

    // short
    short shorts = 1000;
    printf("short: %hd\n", shorts);

    // long
    long longs = 1000000L;
    printf("long: %ld\n", longs);

    // long long
    long long long_long = 1000000000LL;
    printf("long long: %lld\n", long_long);

    // unsigned - переменная не может быть отрицательной
    unsigned int unsigned_int = 4294967295U;
    printf("unsigned int: %u\n", unsigned_int);

    return 0;
}
