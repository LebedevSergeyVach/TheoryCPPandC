#include <stdio.h>

/*
    Времена года

    Зима начинается с 1 декабря и длится до последнего дня февраля,
    весна начинается с 1 марта и длится до последнего дня (31) мая,
    лето начинается с 1 июня и длится до 31 августа,
    осень начинается с 1 сентября и длится до 30 ноября
*/

// Дата описывается структурой YYYY-MM-DD - Формат сезонов
typedef struct
{
    int yy;  // год
    char mm; // месяц
    char dd; // день
} Data;

// Времена года описываются структурой
typedef struct
{
    int yy;      // год
    char season; // время года (зима - 0, весна - 1, лето - 2, осень - 3)
    int day;     // день от начала текущего времени года
} Season;

// получает параметры даты с консоли (три целых числа через тире:
// YYYY-MM-DD)
// Например, 2020-12-13
Data getData();

// Печатает дату в формате: YYYY-MM-DD завершая переносом строки (\n)
void printData(Data data);

// конвертирует дату в формат Season и возвращает это значение
// зима с 1 декабря по конец февраля, весна - с 1 марта по 31 мая, лето - с 1 июня по 31 августа,
// осень - с 1 сентября по 30 ноября
Season convToSeas(Data data);

//  печать времени года в формате: YYYY-SS-DD (SS - номер времени года,
// DD - день от начала времени года, завершая переносом строки
void printSeas(Season season);

int main()
{
    Data dat;
    Season seas;
    dat = getData();
    printData(dat);
    seas = convToSeas(dat);
    printSeas(seas);

    return 0;
}

// получает параметры даты с консоли (три целых числа через тире:
// YYYY-MM-DD)
// Например, 2020-12-13
Data getData()
{
    Data data;
    scanf("%04d-%02d-%02d", &data.yy, &data.mm, &data.dd);

    return data;
}

// Печатает дату в формате: YYYY-MM-DD завершая переносом строки (\n)
void printData(Data data)
{
    printf("%04d-%02d-%02d\n", data.yy, data.mm, data.dd);
}

// конвертирует дату в формат Season и возвращает это значение
// зима с 1 декабря по конец февраля, весна - с 1 марта по 31 мая, лето - с 1 июня по 31 августа,
// осень - с 1 сентября по 30 ноября
Season convToSeas(Data data)
{
    Season season;

    season.yy = data.yy;

    switch (data.mm)
    {
    // Зима
    case 1:
        season.season = 0;
        season.day = data.dd + 31;
        break;
    case 2:
        season.season = 0;
        season.day = data.dd + 62;
        break;
    // Весна
    case 3:
        season.season = 1;
        season.day = data.dd;
        break;
    case 4:
        season.season = 1;
        season.day = data.dd + 31;
        break;
    case 5:
        season.season = 1;
        season.day = data.dd + 61;
        break;
    // Лето
    case 6:
        season.season = 2;
        season.day = data.dd;
        break;
    case 7:
        season.season = 2;
        season.day = data.dd + 30;
        break;
    case 8:
        season.season = 2;
        season.day = data.dd + 61;
        break;
    // Осень
    case 9:
        season.season = 3;
        season.day = data.dd;
        break;
    case 10:
        season.season = 3;
        season.day = data.dd + 30;
        break;
    case 11:
        season.season = 3;
        season.day = data.dd + 61;
        break;
    // Зима
    case 12:
        season.season = 0;
        season.day = data.dd;
        break;
    default:
        season.season = data.mm;
        season.day = data.dd;
        break;
    }

    return season;
}

//  печать времени года в формате: YYYY-SS-DD (SS - номер времени года,
// DD - день от начала времени года, завершая переносом строки
void printSeas(Season season)
{
    printf("%04d-%02d-%02d\n", season.yy, season.season, season.day);
}
