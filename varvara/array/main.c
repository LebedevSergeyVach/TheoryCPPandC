/**
 * Сортировка введенного динамического массива
 * • реализация алгоритма сортировки пузырьком
 * • направление сортировки задает пользователь с клавиатуры при запуске
 * • реализация единой функции сортировки в соответствии с математической моделью, за счет выделения функций
 * Compare() и Replace()
 * • реализуйте в программе несколько функций сравнения для различных типов сортировки (по убыванию, по
 * возрастанию, по абсолютному значению). Передайте указатель на соответствующую функцию сравнения в
 * единую функцию сортировки
 */

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define ARRAY_SIZE_MAX 100

int compareAscending(int firstNumber, int secondNumber)
{
    return firstNumber > secondNumber;
}

int compareDescending(int firstNumber, int secondNumber)
{
    return firstNumber < secondNumber;
}

int compareAbsolute(int firstNumber, int secondNumber)
{
    return fabs(firstNumber) > fabs(secondNumber);
}

void replace(int *firstNumber, int *secondNumber)
{
    int temp = *firstNumber;
    *firstNumber = *secondNumber;
    *secondNumber = temp;
}

void bubbleSort(int *arrayInt, int sizeArray, int (*Compare)(int, int))
{
    for (int i = 0; i < sizeArray - 1; i++)
    {
        for (int j = 0; j < sizeArray - i - 1; j++)
        {
            if (Compare(arrayInt[j], arrayInt[j + 1]))
            {
                replace(&arrayInt[j], &arrayInt[j + 1]);
            }
        }
    }
}

void inputSizeArrayInt(int *pointer)
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

void inputChoiceSotr(int *pointer)
{
    while (1)
    {
        printf("Выберите направление сортировки:\n1. По возрастанию\n2. По убыванию\n3. По абсолютному значению\n_: ");

        if (scanf("%d", pointer) != 1 || getchar() != '\n')
        {
            printf("Введено неверное значение для выбора сортировки!\n");

            while (getchar() != '\n')
                ;

            continue;
        }

        if (*pointer != 1 && *pointer != 2 && *pointer != 3)
        {
            printf("Введено неверное значение для выбора сортировки! Не 1, 2 и 3!\n");

            continue;
        }

        break;
    }
}

int main()
{
    int sizeArray;
    inputSizeArrayInt(&sizeArray);

    int *arrayDynamicInt = (int *)malloc(sizeArray * sizeof(int));

    if (arrayDynamicInt == NULL)
    {
        printf("Не удалось создать динамичческий массив размером: %d\n", sizeArray);
        return 1;
    }

    inputArrayInt(arrayDynamicInt, sizeArray);

    int choiceSort;
    inputChoiceSotr(&choiceSort);

    // Указатель на функцию сравнения
    int (*Compare)(int, int) = NULL;

    switch (choiceSort)
    {
    case 1:
        Compare = compareAscending;
        break;
    case 2:
        Compare = compareDescending;
        break;
    case 3:
        Compare = compareAbsolute;
        break;
    default:
        printf("Неверный выбор!\n");
        free(arrayDynamicInt);
        return 1;
    }

    bubbleSort(arrayDynamicInt, sizeArray, Compare);

    printf("Отсортированный массив:\n");
    printArrayInt(arrayDynamicInt, sizeArray);

    free(arrayDynamicInt);

    return 0;
}
