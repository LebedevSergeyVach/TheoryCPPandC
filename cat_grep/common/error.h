#ifndef ERROR_H
#define ERROR_H

#include <stdio.h>
#include <unistd.h>

void error_used_command(int *program_execution, const char *name);
void error_check_file_exists(int *program_execution, int argc, char *argv[]);

#endif
