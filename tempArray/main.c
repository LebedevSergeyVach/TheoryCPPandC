#include <stdio.h>
#include <math.h>

#include "colorOut.h"

/**
 * Программа по вычислению максимума, минимума, среднего значения, среднеквадратичного отклонения во
 * введенном статическом массиве
 * • максимальный размер массива задается #define, а актуальный размер – пользователем с клавиатуры при запуске
 * • хранение массива в виде глобальной переменной
 * • целочисленные элементы массива задаются пользователем с клавиатуры
 * • написание собственных функций Min(), Max(), Mean(), RMS()
 * • используйте массивы и оператор [] для доступа к элементам
 */

#include <stdio.h>
#include <math.h>

#define ARRAY_SIZE_MAX 100

void inputValueInt(int *pointer)
{
    while (1)
    {
        printf("Задайте размер массива" GREEN "(int)" RESET ": ");

        if (scanf("%d", pointer) != 1 || getchar() != '\n')
        {
            printf(RED "Введено неверное значение для размера массива!\n" RESET);

            while (getchar() != '\n')
                ;

            continue;
        }

        if (*pointer <= 0 || *pointer > ARRAY_SIZE_MAX)
        {
            printf(RED "Введен неверный размер массива!\n" RESET);

            continue;
        }

        break;
    }
}

void printArrayInt(int *arrayInt, int sizeArray)
{
    for (int i = 0; i < sizeArray; i++)
    {
        printf("%d", arrayInt[i]);

        if (i < sizeArray - 1)
        {
            printf(", ");
        }
    }

    printf("\n");
}

void inputArrayInt(int *arrayInt, int sizeArray)
{
    while (1)
    {
        printf("Введите знчения для массива, длиной = " BLUE "%d" RESET ": " RESET, sizeArray);

        for (int i = 0; i < sizeArray; i++)
        {
            scanf("%d", &arrayInt[i]);
        }

        if (getchar() != '\n')
        {
            printf(RED "Были введены неверные данные!\n" RESET);
            while (getchar() != '\n')
                ;

            continue;
        }

        break;
    }
}

int Min(int *arrayInt, int sizeArray)
{
    int min = arrayInt[0];

    for (int i = 1; i < sizeArray; i++)
    {
        if (arrayInt[i] < min)
        {
            min = arrayInt[i];
        }
    }

    return min;
}

int Max(int *arrayInt, int sizeArray)
{
    int max = arrayInt[0];

    for (int i = 1; i < sizeArray; i++)
    {
        if (arrayInt[i] > max)
        {
            max = arrayInt[i];
        }
    }

    return max;
}

float Mean(int *arrayInt, int sizeArray)
{
    int sum = 0;

    for (int i = 0; i < sizeArray; i++)
    {
        sum += arrayInt[i];
    }

    return (float)sum / sizeArray;
}

float RMS(int *arrayInt, int sizeArray)
{
    float mean = Mean(arrayInt, sizeArray);
    float sum_squared_diff = 0;

    for (int i = 0; i < sizeArray; i++)
    {
        sum_squared_diff += (arrayInt[i] - mean) * (arrayInt[i] - mean);
    }

    return sqrt(sum_squared_diff / sizeArray);
}

int main()
{
    int size;
    inputValueInt(&size); // НАШ КРУТОЙ РОССИЙСКИЙ СКАНФ ПОД ЖЕСТКИМИ СТЕРОИДАМИ

    int array[size];
    inputArrayInt(array, size);

    printf("Для данных значений массива: ");
    printArrayInt(array, size);

    printf("Минимальное значение: " BLUE "%d" RESET ".\nМаксимальное значение: " BLUE "%d" RESET
           ".\nСреднее значение: " BLUE "%f" RESET ".\nСреднеквадратичное отклонение: " BLUE "%f" RESET ".\n",
           Min(array, size), Max(array, size), Mean(array, size), RMS(array, size));

    return 0;
}
