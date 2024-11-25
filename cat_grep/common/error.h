#ifndef ERROR_H
#define ERROR_H

#include <stdio.h>
#include <getopt.h>
#include <unistd.h>

// Функция для вывода сообщения об ошибке неправильного использования команды cat
void error_used_command_cat(int *program_execution, const char *name);
// Функция для вывода сообщения об ошибке неправильного использования команды grep
void error_used_command_grep(int *program_execution, const char *name);
// Функция для проверки существования файлов, переданных в качестве аргументов
void error_check_file_exists(int *program_execution, int argc, char *argv[]);

#endif
