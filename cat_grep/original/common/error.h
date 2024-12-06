#ifndef ERROR_H
#define ERROR_H

#include <getopt.h>
#include <stdio.h>
#include <unistd.h>

/**
 * Выводит сообщение об ошибке о неверном использовании команды `cat` и
 * устанавливает флаг ошибки.
 *
 * @param program_execution Указатель на переменную, хранящую статус выполнения
 * программы.
 * @param name              Имя команды, которое будет использовано в сообщении
 * об ошибке.
 *
 * @return void
 */
void error_used_command_cat(int *program_execution, const char *name);

/**
 * Выводит сообщение об ошибке о неверном использовании команды `grep` и
 * устанавливает флаг ошибки.
 *
 * @param program_execution Указатель на переменную, хранящую статус выполнения
 * программы.
 * @param name              Имя команды, которое будет использовано в сообщении
 * об ошибке.
 *
 * @return void
 */
void error_used_command_grep(int *program_execution, const char *name);

/**
 * Проверяет существование файлов, переданных в качестве аргументов командной
 * строки, и выводит сообщение об ошибке, если файл не существует.
 *
 * @param program_execution Указатель на переменную, хранящую статус выполнения
 * программы.
 * @param argc              Количество аргументов командной строки.
 * @param argv              Массив аргументов командной строки.
 *
 * @return void
 */
void error_check_file_exists(int *program_execution, int argc, char *argv[]);

#endif
