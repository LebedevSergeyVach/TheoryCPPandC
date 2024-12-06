#ifndef S21_PROCESS_CAT_FILE_H
#define S21_PROCESS_CAT_FILE_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "s21_flags_cat.h"

#define MAX_LINE_LENGTH 4096

/**
 * Выводит один символ с учетом установленных флагов.
 *
 * @param uc                Символ для вывода.
 * @param flags             Битовая маска флагов, определяющая режимы вывода.
 * @param line_number       Указатель на номер текущей строки (-n и -b).
 * @param in_nonblank_line  Указатель на флаг, непустая строка (-b).
 * @param new_line_start    Указатель на флаг, начало новой строи (-n).
 *
 * @return void
 */
void print_char(unsigned char uc, int flags, int *line_number,
                int *in_nonblank_line, int *new_line_start);

/**
 * Обрабатывает файл и выводит его содержимое с учетом установленных флагов.
 *
 * @param file              Указатель на файл для обработки.
 * @param flags             Битовая маска флагов, определяющая режимы вывода.
 *
 * @return void
 */
void process_file_cat(FILE *file, int flags);

#endif
