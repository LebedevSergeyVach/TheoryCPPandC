#ifndef S21_PROCESS_GREP_FILE_H
#define S21_PROCESS_GREP_FILE_H

#include <stdio.h>
#include <stdlib.h>
#include <regex.h>

#include "s21_flags_grep.h"
#include "../common/color_out.h"

#define MAX_LINE_LENGTH 4096

// Функция для обработки файла с учетом флагов
void process_file_grep(int flags, const char *pattern, FILE *file, const char *filename, int file_count, int *program_execution);

#endif
