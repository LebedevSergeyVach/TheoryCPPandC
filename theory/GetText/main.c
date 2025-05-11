#include "lib/correct_text.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define TERMINATOR '#'

void choiceStdinText(int *pointer);
FILE *selectInputSource(int choice);
char *myRealloc(char *oldPointer, size_t oldAllocatedSize, size_t newAllocatedSize, size_t dataSize);
char *GetText(FILE *stream, char terminator);

/**
 * Реализация функции ввода текста произвольного размера: char* GetText(FILE* stream, char terminator)
 * • Конец текста обозначается выбранным символом terminator (например, '#' или '\n')
 * • Возвращается строка в стиле C (нуль-терминированная), не включающая символа terminator
 * • Выделение точного количества необходимой памяти (собственная функция перевыделения памяти безиспользования realloc() )
 * • Использование функции корректировки из задачи 9
 * • Ввод текста из консоли или файла (выбор задается с консоли)
 */
int main()
{
    int choice;
    choiceStdinText(&choice);

    FILE *inputSource = selectInputSource(choice);
    if (inputSource == NULL)
    {
        fprintf(stderr, "Не удалось открыть источник ввода!\n");
        return 1;
    }

    printf("Введите текст, заканчивающийся на %c:\n", TERMINATOR);
    char *text = GetText(inputSource, TERMINATOR);

    // Если ввод был из файла, закрываем его
    if (choice == 2)
    {
        fclose(inputSource);
    }

    if (text != NULL)
    {
        printf("Отредактированный текст:\n%s\n", text);
        free(text);
    }
    else
    {
        fprintf(stderr, "Произошла ошибка!\n");
        return 1;
    }

    return 0;
}

void choiceStdinText(int *pointer)
{
    while (1)
    {
        printf("Выберите способ ввода текста:\n1. Ввод текста через консоль.\n2. Чтение текста из файла\n_: ");

        if (scanf("%d", pointer) != 1 || getchar() != '\n')
        {
            printf("Введено неверное значение для выбора ввода текста!\n");

            while (getchar() != '\n')
                ;

            continue;
        }

        if (*pointer != 1 && *pointer != 2)
        {
            printf("Введено неверное значение для выбора ввода текста!\n");

            continue;
        }

        break;
    }
}

// Выбор источника ввода (консоль или файл)
FILE *selectInputSource(int choice)
{
    if (choice == 1)
    {
        return stdin;
    }
    else
    {
        char filename[256];

        printf("Введите относительный путь до файла: ");
        scanf("%255s", filename);

        while (getchar() != '\n')
            ; // Очистка буфера

        FILE *file = fopen(filename, "r");

        if (file == NULL)
        {
            fprintf(stderr, "Ошибка открытия файла %s\n", filename);
            return NULL;
        }

        return file;
    }
}

// Улучшенная функция перевыделения памяти с учётом реального размера данных
char *myRealloc(char *oldPointer, size_t oldAllocatedSize, size_t newAllocatedSize, size_t dataSize)
{
    // Нельзя создать массив с размером меньше 0
    if (newAllocatedSize < 0)
    {
        return NULL;
    }

    // Если запрашивается новый размер 0 - освобождаем память
    if (newAllocatedSize == 0)
    {
        free(oldPointer);
        return NULL;
    }

    // Если старый указатель NULL - просто выделяем новую память
    if (oldPointer == NULL)
    {
        return (char *)malloc(newAllocatedSize);
    }

    // Выделяем новый блок памяти
    char *newPointer = (char *)malloc(newAllocatedSize);
    if (newPointer == NULL)
    {
        return NULL;
    }

    // Копируем только значимые данные (не больше, чем новый размер)
    size_t bytesToCopy = dataSize < newAllocatedSize ? dataSize : newAllocatedSize;
    memcpy(newPointer, oldPointer, bytesToCopy);

    // Освобождаем старый блок
    free(oldPointer);

    return newPointer;
}

char *GetText(FILE *stream, char terminator)
{
    size_t capacity = 100; // Начальная емкость буфера (вместимость)
    size_t sizeData = 0;   // Текущий размер введенного текста
    char ch;               // Переменная для чтения символов

    char *buffer = (char *)malloc(capacity * sizeof(char));
    if (buffer == NULL)
    {
        fprintf(stderr, "Ошибка выделения динамической памяти!\n");
        return NULL;
    }

    // Читаем символы до терминатора или EOF
    while ((ch = fgetc(stream)) != terminator && ch != EOF)
    {

        // Если буфер заполнен, увеличиваем его размер
        if (sizeData >= capacity - 1) // -1 для нуль-терминатора
        {
            size_t newCapacity = capacity * 2;
            // char *temp = (char *)realloc(buffer, capacity * sizeof(char));
            char *temp = myRealloc(buffer, capacity, newCapacity, sizeData);

            if (temp == NULL)
            {
                fprintf(stderr, "Ошибка перевыделения динамической памяти!\n");
                free(buffer);
                return NULL;
            }

            buffer = temp;
            capacity = newCapacity;
        }

        // Добавляем символ в буфер
        buffer[sizeData++] = ch;
    }

    // Добавляем нуль-терминатор
    buffer[sizeData++] = '\0';

    // коректировка текста
    if (!correctText(buffer, capacity))
    {
        fprintf(stderr, "Не удалось отредактировать текст!\n");
        free(buffer);
        return NULL;
    }

    // Оптимизируем память, уменьшая буфер до минимально необходимого размера
    // char *result = (char *)realloc(buffer, (sizeData + 1) * sizeof(char));
    char *result = (char *)myRealloc(buffer, capacity, sizeData + 1, sizeData);
    if (result == NULL)
    {
        fprintf(stderr, "Не удалось уменьшить размер выделенной памяти для строки!\n");
        free(buffer);
        return NULL;
    }

    return result;
}
