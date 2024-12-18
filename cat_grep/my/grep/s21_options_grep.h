#ifndef S21_OPTIONS_GREP_H
#define S21_OPTIONS_GREP_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <getopt.h>

#include "s21_flags_grep.h"
#include "s21_read_and_combination_patterns.h"
#include "s21_read_patterns_from_file.h"
#include "../common/error.h"

// Функция для парсинга опций командной строки
int parse_options(int argc, char *argv[], int *flags, char **pattern, int *pattern_dynamic, int *program_execution);

#endif
