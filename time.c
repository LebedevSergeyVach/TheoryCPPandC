#include <stdio.h>
#include <time.h>

// Определение структуры TimeIsNow, которая содержит поля для часов, минут и секунд
typedef struct TimeIsNow
{
    int hours, minuts, seconds;
} TimeIsNow;

// Определение структуры DataIsNow, которая содержит поля для дней, месяцев и лет
typedef struct DataIsNow
{
    int days, months, years;
} DataIsNow;

// Функция для получения текущего времени и записи его в структуру TimeIsNow
// Параметр TimeIsNow *time_now: Это указатель на структуру TimeIsNow
void getTimeIsNow(TimeIsNow *time_now)
{
    // Получаем текущее время в виде количества секунд с начала эпохи (1 января 1970 года)
    time_t current_time;
    time(&current_time);

    // Преобразуем время в структуру tm, которая содержит компоненты даты и времени
    struct tm *local_time = localtime(&current_time);

    // Записываем часы, минуты и секунды в поля структуры time_now
    // Оператор -> используется для доступа к полям структуры через указатель
    time_now->hours = local_time->tm_hour;
    time_now->minuts = local_time->tm_min;
    time_now->seconds = local_time->tm_sec;
}

// Функция для получения текущей даты и записи его в структуру DataIsNow
// Параметр DataIsNow *data_now: Это указатель на структуру DataIsNow
void getDataIsNow(DataIsNow *data_now)
{
    // Получаем текущее время в виде количества секунд с начала эпохи (1 января 1970 года)
    time_t current_time;
    time(&current_time);

    // Преобразуем время в структуру tm, которая содержит компоненты даты и времени
    struct tm *local_time = localtime(&current_time);

    // Записываем день, месяц и год в поля структуры data_now
    // Оператор -> используется для доступа к полям структуры через указатель
    data_now->days = local_time->tm_mday;
    data_now->months = local_time->tm_mon;
    data_now->years = local_time->tm_year + 1900;
}

// Функция для вывода времени из структуры TimeIsNow в формате чч:мм:сс
void printTimeIsNow(TimeIsNow time)
{
    // Выводим время в формате чч:мм:сс с ведущими нулями для однозначных чисел
    printf("%02d:%02d:%02d\n", time.hours, time.minuts, time.seconds);
}

// Функция для вывода даты из структуры DataIsNow в формате дд:мм:гггг
void printDataIsNow(DataIsNow data)
{
    printf("%02d:%02d:%04d\n", data.days, data.months, data.years);
}

// Функция для вывода циферблата с временем и датой из структур TimeIsNow, DataIsNow
void printDialTimeData(TimeIsNow time, DataIsNow data)
{
    printf(
        "\n|  %02d:%02d:%02d  |\n-------------\n| %02d:%02d:%04d |\n",
        time.hours, time.minuts, time.seconds,
        data.days, data.months, data.years);
}

int main()
{
    TimeIsNow time;
    // Вызываем функцию getTimeIsNow, передавая ей адрес переменной time
    // Это позволяет функции изменить значения полей переменной time
    getTimeIsNow(&time);
    printTimeIsNow(time);

    DataIsNow data;
    // Вызываем функцию getDataIsNow, передавая ей адрес переменной data
    // Это позволяет функции изменить значения полей переменной data
    getDataIsNow(&data);
    printDataIsNow(data);

    printDialTimeData(time, data);

    return 0;
}
