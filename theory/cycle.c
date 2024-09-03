#include <stdio.h>

// Функция, возращающее перевернутое число 103020 -> 20301
int revesedNumber(int number);

/* Циклы for, while, do while и goto */
int main()
{
    // [i, 5]
    for (int i = 0; i <= 5; i++)
    {
        printf("Iteration %d\n", i);
    }

    int j = 0;
    // [j, 5]
    while (j <= 5)
    {
        printf("While iteration %d\n", j);
        j++;
    }

    int i = 0;
    // [i, 5]
    do
    {
        printf("Iteration %d\n", i);
        i++;
    } while (i <= 5);

    /*
        Несколько выражений в первой и последней части for
        Напишем вычисление факториала n! через цикл for
        Начиная со стандарта С99 можно объявлять переменную i прямо в операторе for. По принципу "где нужно, там и объявили".
    */
    for (res = 1, i = 1; i <= n; res *= i, i++)
    {
        ; // подчеркиваем, что мы осознаем, что в цикле тело пустое
    }
    printf("%d! = %d\n", n, res);

    int number, reversed;
    scanf("%d", &number);

    reversed = revesedNumber(number);
    printf("Reversed number -> %d\n", reversed);

    /*
        goto cycle

        Когда использовать goto:
        Использование goto понижает читаемость кода.
        Бесконечный цикл лучше написать как while(1) или for(;;).

        goto стоит использовать только в 3 случаях:
        - break по внешнему циклу.
        - continue по внешнему циклу.
        - обработка ошибок (об этом будет подробно рассказано в курсе про IPC).
    */
    int i = 0;

// Метка start: для goto
start:
    // [i; 4]
    if (i < 5)
    {
        printf("i = %d\n", i);
        i++;
        goto start;
    }

    printf("End cycle goto\n");

    return 0;
}

// Функция, возращающее перевернутое число 103020 -> 20301
int revesedNumber(int number)
{
    int reversed = 0;

    while (number > 0)
    {
        reversed = reversed * 10 + number % 10;
        number /= 10;
    }

    return reversed;
}
