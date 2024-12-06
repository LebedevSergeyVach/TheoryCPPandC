#ifndef S21_PROCESS_GREP_FILE_H
#define S21_PROCESS_GREP_FILE_H

#include <regex.h>
#include <stdio.h>
#include <stdlib.h>

#include "s21_flags_grep.h"

#define MAX_LINE_LENGTH 4096

/**
 * Обрабатывает файл и выполняет поиск по шаблону с учетом установленных флагов.
 *
 * @param flags             Битовая маска флагов, определяющая режимы поиска.
 * @param pattern           Строка, содержащая шаблон для поиска.
 * @param file              Указатель на файл для обработки.
 * @param filename          Имя файла для вывода в случае совпадения.
 * @param file_count        Количество обрабатываемых файлов.
 * @param program_execution Указатель на переменную, хранящую статус выполнения
 * программы.
 *
 * @return void
 */
void process_file_grep(int flags, const char *pattern, FILE *file,
                       const char *filename, int file_count,
                       int *program_execution);

#endif
