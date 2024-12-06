#ifndef S21_READ_PATTERNS_FROM_FILE_H
#define S21_READ_PATTERNS_FROM_FILE_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE_LENGTH 4096

/**
 * Читает шаблоны из файла и объединяет их в одну строку, разделяя символом '|'.
 *
 * @param filename          Имя файла, содержащего шаблоны.
 * @param pattern           Указатель на строку, которая будет содержать
 * объединенные шаблоны.
 * @param program_execution Указатель на переменную, хранящую статус выполнения
 * программы.
 *
 * @return void
 */
void read_patterns_from_file(const char *filename, char **pattern,
                             int *program_execution);

#endif
