#ifndef S21_OPTIONS_GREP_H
#define S21_OPTIONS_GREP_H

#include <getopt.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "../common/error.h"
#include "s21_flags_grep.h"
#include "s21_read_and_combination_patterns.h"
#include "s21_read_patterns_from_file.h"

/**
 * Парсит аргументы командной строки для команды `grep` и устанавливает
 * соответствующие флаги и шаблоны.
 *
 * @param argc              Количество аргументов командной строки.
 * @param argv              Массив аргументов командной строки.
 * @param flags             Указатель на битовую маску флагов, которые будут
 * установлены в зависимости от аргументов.
 * @param pattern           Указатель на строку, которая будет содержать шаблон
 * для поиска.
 * @param pattern_dynamic   Указатель на флаг, указывающий, был ли шаблон
 * динамически выделен.
 * @param program_execution Указатель на переменную, хранящую статус выполнения
 * программы.
 *
 * @return int              Возвращает индекс следующего аргумента после
 * обработки опций.
 */
int parse_options(int argc, char *argv[], int *flags, char **pattern,
                  int *pattern_dynamic, int *program_execution);

#endif
