#ifndef S21_PROCESS_CAT_FILE_H
#define S21_PROCESS_CAT_FILE_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "s21_flags_cat.h"
#include "../common/color_out.h"

#define MAX_LINE_LENGTH 4096

// Функция для обработки файла с учетом флагов
void process_file_cat(FILE *file, int flags);

#endif
