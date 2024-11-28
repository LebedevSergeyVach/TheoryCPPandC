#include "s21_read_patterns_from_file.h"

char* read_patterns_from_file(const char *filename, int *program_execution)
{
    // Открываем файл с шаблонами для чтения
    FILE *file = fopen(filename, "r");
    if (file == NULL)
    {
        // Если файл не удалось открыть, выводим сообщение об ошибке
        fprintf(stderr, "Не удалось открыть файл с шаблонами: %s\n", filename);
        // Устанавливаем флаг ошибки выполнения программы
        *program_execution = 1;
        // Возвращаем NULL, чтобы указать на ошибку
        return NULL;
    }

    // Инициализируем указатель на строку, которая будет содержать все шаблоны
    char *patterns = NULL;
    // Буфер для чтения строк из файла
    char line[MAX_LINE_LENGTH]; 

    // Читаем строки из файла до тех пор, пока не достигнем конца файла
    while (fgets(line, sizeof(line), file))
    {
        // Вычисляем длину текущей строки
        size_t len = strlen(line);
        // Если строка заканчивается символом новой строки, удаляем его
        if (line[len - 1] == '\n')
        {
            line[len - 1] = '\0';
        }

        // Если patterns еще не инициализирован (первая строка)
        if (patterns == NULL)
        {
            // Выделяем память для первой строки (плюс один символ для завершающего нуля)
            patterns = malloc(len + 1);
            // Проверяем, удалось ли выделить память
            if (patterns == NULL)
            {
                // Закрываем файл
                fclose(file);
                // Выводим сообщение об ошибке
                fprintf(stderr, "Ошибка выделения памяти\n");
                // Устанавливаем флаг ошибки выполнения программы
                *program_execution = 1;
                // Возвращаем NULL, чтобы указать на ошибку
                return NULL;
            }
            // Копируем строку в patterns
            strcpy(patterns, line);
        }
        else
        {
            // Если patterns уже инициализирован (не первая строка)
            // Выделяем новую память для объединенной строки (текущий patterns + новая строка + разделитель "|" + завершающий ноль)
            char *new_patterns = realloc(patterns, strlen(patterns) + len + 2);
            // Проверяем, удалось ли выделить память
            if (new_patterns == NULL)
            {
                // Освобождаем уже выделенную память для patterns
                free(patterns);
                // Закрываем файл
                fclose(file);
                // Выводим сообщение об ошибке
                fprintf(stderr, "Ошибка выделения памяти\n");
                // Устанавливаем флаг ошибки выполнения программы
                *program_execution = 1;
                // Возвращаем NULL, чтобы указать на ошибку
                return NULL;
            }
            // Обновляем указатель на patterns
            patterns = new_patterns;
            // Добавляем разделитель "|"
            strcat(patterns, "|");
            // Добавляем новую строку
            strcat(patterns, line);
        }
    }

    // Закрываем файл после чтения всех строк
    fclose(file);

    // Возвращаем строку с объединенными шаблонами
    return patterns;
}