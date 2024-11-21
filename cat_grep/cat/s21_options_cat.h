#ifndef S21_OPTIONS_CAT_H
#define S21_OPTIONS_CAT_H

#include <getopt.h>

#include "s21_flags_cat.h"
#include "../common/error.h"

// Функция для парсинга опций командной строки
int parse_options(int argc, char *argv[], int *flags);

#endif
