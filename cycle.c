#include <stdio.h>

// Функция, возращающее перевернутое число 103020 -> 20301
int revesedNumber(int number);

/* Циклы for, while и do while */
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
    do {
        printf("Iteration %d\n", i);
        i++;
    } while (i <= 5);

    int number, reversed;
    scanf("%d", &number);

    reversed = revesedNumber(number);
    printf("Reversed number -> %d\n", reversed);

    return 0;
}

// Функция, возращающее перевернутое число 103020 -> 20301
int revesedNumber(int number)
{
    int reversed = 0;

    while (number > 0) {
        reversed = reversed * 10 + number % 10;
        number /= 10;
    }

    return reversed;
}

