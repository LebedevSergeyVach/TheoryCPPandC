#ifndef S21_OPTIONS_CAT_H
#define S21_OPTIONS_CAT_H

#include <getopt.h>

#include "../common/error.h"
#include "s21_flags_cat.h"

/**
 * Парсит аргументы командной строки и устанавливает соответствующие флаги.
 *
 * @param argc              Количество аргументов командной строки.
 * @param argv              Массив аргументов командной строки.
 * @param flags             Указатель на битовую маску флагов, которые будут
 * установлены в зависимости от аргументов.
 *
 * @return int              Возвращает статус выполнения программы (0 - успешно,
 * ненулевое значение - ошибка).
 */
int parse_options(int argc, char *argv[], int *flags);

#endif
