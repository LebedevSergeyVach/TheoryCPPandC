#ifndef S21_OPTIONS_GREP_H
#define S21_OPTIONS_GREP_H

#include <getopt.h>

#include "s21_flags_grep.h"
#include "../common/error.h"

// Функция для парсинга опций командной строки
int parse_options(int argc, char *argv[], int *flags, char **pattern, int *program_execution);

#endif
