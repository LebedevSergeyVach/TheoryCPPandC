#include <stdio.h>

/*
    ? : - тернарный оператор

    && - логическое И (AND, конъюнкция)
    || - логическое ИЛИ (OR, дизъюнкция)
    ! - логическое отрицание (NOT)
*/


/*
    Даны 2 целых числа.
    Напечатайте числа через пробел.
    Напечатайте минимальное из этих чисел на следующей строке.
*/

int main()
{
    int a, b;
    scanf("%d%d", &a, &b);
    printf("%d %d\n%d\n", a, b, a < b ? a : b);

    // switch case
    switch (a % 10)
    {
    case 1:
        printf("One");
        break;
    case 2:
        printf("Two");
        break;
    case 3:
        printf("Three");
        break;
    case 4:
        printf("Four");
        break;
    case 5:
        printf("Five");
        break;
    default:
        printf("NO");
        break;
    }

    return 0;
}
