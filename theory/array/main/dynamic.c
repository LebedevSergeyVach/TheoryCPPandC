/**
 * Программа по вычислению максимума, минимума, среднего значения, среднеквадратичного отклонения во
 * введенном статическом массиве
 * • максимальный размер массива задается #define, а актуальный размер – пользователем с клавиатуры при запуске
 * • хранение массива в виде глобальной переменной
 * • целочисленные элементы массива задаются пользователем с клавиатуры
 * • написание собственных функций Min(), Max(), Mean(), RMS()
 * • используйте массивы и оператор [] для доступа к элементам
 *
 * UPDATE: Переписть код на использование динамической памяти, указателей и арарифметики указателей
 */

#include <stdio.h>
#include <math.h>

#define ARRAY_SIZE_MAX 100

void inputValueInt(int *pointer)
{
    while (1)
    {
        printf("Задайте размер массива (int): ");

        if (scanf("%d", pointer) != 1 || getchar() != '\n')
        {
            printf("Введено неверное значение для размера массива!\n");

            while (getchar() != '\n')
                ;

            continue;
        }

        if (*pointer <= 0 || *pointer > ARRAY_SIZE_MAX)
        {
            printf("Введен неверный размер массива!\n");

            continue;
        }

        break;
    }
}

void printArrayInt(int *arrayInt, int sizeArray)
{

    for (int *pointer = arrayInt; pointer - arrayInt < sizeArray; pointer++)
    {
        printf("%d", *(pointer));

        if (pointer < arrayInt + sizeArray - 1)
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
        printf("Введите знчения для массива, длиной = %d: ", sizeArray);

        for (int *pointer = arrayInt; pointer - arrayInt < sizeArray; pointer++)
        {
            scanf("%d", pointer);
        }

        if (getchar() != '\n')
        {
            printf("Были введены неверные данные!\n");
            while (getchar() != '\n')
                ;

            continue;
        }

        break;
    }
}

int Min(int *arrayInt, int sizeArray)
{
    int min = *arrayInt;

    for (int *pointer = arrayInt + 1; pointer - arrayInt < sizeArray; pointer++)
    {
        if (*pointer < min)
        {
            min = *pointer;
        }
    }

    return min;
}

int Max(int *arrayInt, int sizeArray)
{
    int max = *arrayInt;

    for (int *pointer = arrayInt + 1; pointer - arrayInt < sizeArray; pointer++)
    {
        if (*pointer > max)
        {
            max = *pointer;
        }
    }

    return max;
}

float Mean(int *arrayInt, int sizeArray)
{
    int sum = 0;

    for (int *pointer = arrayInt; pointer - arrayInt < sizeArray; pointer++)
    {
        sum += *pointer;
    }

    return (float)sum / sizeArray;
}

float RMS(int *arrayInt, int sizeArray)
{
    float mean = Mean(arrayInt, sizeArray);
    float sum_squared_diff = 0;

    for (int *pointer = arrayInt; pointer - arrayInt < sizeArray; pointer++)
    {
        sum_squared_diff += (*pointer - mean) * (*pointer - mean);
    }

    return sqrt(sum_squared_diff / sizeArray);
}

int main()
{
    int size;

    inputValueInt(&size); // НАШ КРУТОЙ РОССИЙСКИЙ СКАНФ ПОД ЖЕСТКИМИ СТЕРОИДАМИ

    int *arrayDinamic = (int *)malloc(size * sizeof(int));

    if (arrayDinamic == NULL)
    {
        printf("Не удалось создать динамичческий массив размером: %d\n", size);
        return 1;
    }

    inputArrayInt(arrayDinamic, size);

    printf("Для данных значений массива: ");
    printArrayInt(arrayDinamic, size);

    printf("Минимальное значение: %d.\nМаксимальное значение: %d.\nСреднее значение: %f.\nСреднеквадратичное отклонение: %f.\n",
           Min(arrayDinamic, size), Max(arrayDinamic, size), Mean(arrayDinamic, size), RMS(arrayDinamic, size));

    free(arrayDinamic);

    return 0;
}
