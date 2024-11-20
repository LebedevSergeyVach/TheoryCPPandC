#ifndef COMMON_H
#define COMMON_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE_LENGTH 4096

// Функция для вывода строки с учетом нумерации
void print_line(const char *line, int number, int is_nonblank);
// Функция для обработки файла с учетом флагов
void process_file(FILE *file, int flags);

#endif
