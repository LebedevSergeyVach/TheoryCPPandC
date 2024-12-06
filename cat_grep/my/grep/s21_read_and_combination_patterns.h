#ifndef S21_READ_AND_COMBINATION_PATTERNS_H
#define S21_READ_AND_COMBINATION_PATTERNS_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "../common/color_out.h"

// Функция для объединения двух шаблонов с разделителем "|"
char* concat_patterns(const char *pattern1, const char *pattern2, int *program_execution);

#endif
