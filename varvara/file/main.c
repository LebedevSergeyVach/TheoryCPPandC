#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_FILE_SIZE_PATH 256
#define MAX_LINE_SIZE_IN_FILE 1024
#define MAX_SIZE_BUFFER_FOR_NUMBER 32

/**
 * Так, он берёт первые 100 значений ( то что в паскалях, после А), и находит среднее, потом следующие 100, и тоже находит у них среднее
 * В итоге должно вывести 7 значений среднего, тк всего 700 значений
 */

// Функция для извлечения значения Паскалей из строки
double extract_pressure_value(const char *line)
{
    // Ищем подстроку "A= " в строке
    const char *start = strstr(line, "A= ");
    if (start == NULL)
    {
        return -1; // Если подстрока не найдена, возвращаем -1 (ошибка)
    }
    start += 3; // Перемещаем указатель на начало числа (после "A= ")

    // Создаем буфер для хранения числа
    char buffer[MAX_SIZE_BUFFER_FOR_NUMBER];
    int i = 0;

    // Копируем число из строки в буфер, заменяя запятую на точку
    while (start[i] != ' ' && start[i] != '\0' && i < sizeof(buffer) - 1)
    {
        buffer[i] = (start[i] == ',') ? '.' : start[i]; // Заменяем запятую на точку
        i++;
    }

    buffer[i] = '\0'; // Завершаем строку нулевым символом

    // Преобразуем строку в число с помощью strtod
    char *end;
    double value = strtod(buffer, &end); // Преобразуем строку в число

    // Проверяем, удалось ли преобразовать строку в число
    if (end == buffer)
    {
        return -1; // Если не удалось, возвращаем -1 (ошибка)
    }

    return value; // Возвращаем извлеченное значение
}

int main()
{
    // Переменная для хранения пути к файлу
    char file_path[MAX_FILE_SIZE_PATH];

    printf("Введите относительный путь от Вашей директории до файла: ");
    scanf("%255s", file_path);

    // Открываем файл для чтения
    FILE *file = fopen(file_path, "r");
    if (file == NULL)
    {
        // Выводим сообщение об ошибке, если файл не удалось открыть
        printf("Произошла ошибка при открытии файла: %s\n", file_path);
        perror("Error open file!\n");

        return 1;
    }

    // Буфер для хранения текущей строки из файла
    char line[MAX_LINE_SIZE_IN_FILE];

    // Переменные для хранения суммы, количества значений и общего количества строк
    double sum = 0;
    int count = 0;
    int total_count = 0;

    // Читаем файл построчно
    while (fgets(line, sizeof(line), file))
    {
        // Извлекаем значение Паскалей из текущей строки
        double value = extract_pressure_value(line);

        // Если значение не удалось извлечь, пропускаем строку
        if (value == -1)
        {
            printf("Не удалось прочить значение в строке: %d\n", total_count + 1);

            continue; // Пропускаем строки, где не удалось извлечь значение
        }

        // Добавляем значение к сумме
        sum += value;
        count++;
        total_count++;

        // Если набрали 100 значений, вычисляем среднее и выводим результат
        if (count == 100)
        {
            double average = sum / count;

            // printf("DEBUG: sum = %.6f; count = %d\n", sum, count);
            printf("Среднее значение для %d-%d значений: %.6f Па\n", total_count - 99, total_count, average);

            // Сбрасываем сумму и счетчик для следующей группы из 100 значений
            sum = 0;
            count = 0;
        }
    }

    // Обработка оставшихся значений (если их меньше 100)
    if (count > 0)
    {
        double average = sum / count;
        // printf("DEBUG: sum = %.6f; count = %d\n", sum, count);
        printf("Среднее значение для последних %d значений: %.6f Па\n", count, average);
    }

    fclose(file);

    return 0;
}
