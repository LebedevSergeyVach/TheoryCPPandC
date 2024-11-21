#ifndef ERROR_H
#define ERROR_H

#include <stdio.h>
#include <getopt.h>
#include <unistd.h>

// Функция для вывода сообщения об ошибке неправильного использования команды
void error_used_command(int *program_execution, const char *name);
// Функция для проверки существования файлов, переданных в качестве аргументов
void error_check_file_exists(int *program_execution, int argc, char *argv[]);

#endif
