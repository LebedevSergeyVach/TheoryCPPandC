#include "error.h"


void error_used_command_cat(int *program_execution, const char *name)
{
    fprintf(
        stderr,
        YELLOW "Неверное использование команды.\nИспользуйте: " BLUE "%s -[benstvET] [file]\n" RESET,
        name);

    *program_execution = 1;
}

void error_used_command_grep(int *program_execution, const char *name) {
        fprintf(
        stderr,
        YELLOW "Неверное использование команды.\nИспользуйте: " BLUE "%s -[-e pattern] -[-p file_patterns] [-ivclnh] [file]\n" RESET,
        name);

    *program_execution = 1;
}

void error_check_file_exists(int *program_execution, int argc, char *argv[])
{
    for (int i = optind; i < argc; i++) {
        if (access(argv[i], F_OK) == -1) {
            fprintf(stderr, YELLOW "Файл " BLUE "'%s' " YELLOW"не существует или недоступен.\n" RESET, argv[i]);
            *program_execution = 1;

            break;
        }
    }
}
