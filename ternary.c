#include <stdio.h>

/*
    ? : - тернарный оператор

    Даны 2 целых числа.
    Напечатайте числа через пробел.
    Напечатайте минимальное из этих чисел на следующей строке.
*/

int main()
{
    int a, b;
    scanf("%d%d", &a, &b);
    printf("%d %d\n%d", a, b, a < b ? a : b);

    switch (a % 10) {
    case 1:
        printf("One");
        break;
    case 2:
        printf("Two");

    default:
        break;
    }

    return 0;
}
