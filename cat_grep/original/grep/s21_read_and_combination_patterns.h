#ifndef S21_READ_AND_COMBINATION_PATTERNS_H
#define S21_READ_AND_COMBINATION_PATTERNS_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/**
 * Объединяет два шаблона в один, разделяя их символом '|'.
 *
 * @param pattern1          Первый шаблон для объединения. Может быть NULL.
 * @param pattern2          Второй шаблон для объединения.
 * @param program_execution Указатель на переменную, хранящую статус выполнения
 * программы.
 *
 * @return char*            Возвращает указатель на строку, содержащую
 * объединенные шаблоны, или NULL в случае ошибки.
 */
char *concat_patterns(const char *pattern1, const char *pattern2,
                      int *program_execution);

#endif
