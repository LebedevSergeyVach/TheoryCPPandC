#ifndef S21_READ_PATTERNS_FROM_FILE_H
#define S21_READ_PATTERNS_FROM_FILE_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE_LENGTH 4096

// Функция для чтения шаблонов из файла
char* read_patterns_from_file(const char *filename, int *program_execution);

#endif
