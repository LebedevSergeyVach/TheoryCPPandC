#include "s21_options_cat.h"

int parse_options(int argc, char *argv[], int *flags)
{
    int program_execution = 0;

    static struct option long_options[] = {
        {"number-nonblank", no_argument, 0, 'b'},
        {"number", no_argument, 0, 'n'},
        {"squeeze-blank", no_argument, 0, 's'},
        {"show-nonprinting", no_argument, 0, 'v'},
        {0, 0, 0, 0}};

    int opt;

    while ((opt = getopt_long(argc, argv, "benstvET", long_options, NULL)) != -1)
    {
        switch (opt)
        {
        case 'b':
            *flags |= FLAG_B;
            break;
        case 'e':
            *flags |= FLAG_E;
            break;
        case 'n':
            *flags |= FLAG_N;
            break;
        case 's':
            *flags |= FLAG_S;
            break;
        case 't':
            *flags |= FLAG_T;
            break;
        case 'E':
            *flags |= FLAG_E;
            break;
        case 'T':
            *flags |= FLAG_T;
            break;
        case 'v':
            *flags |= FLAG_V;
            break;
        default:
            error_used_command_cat(&program_execution, argv[0]);
            break;
        }
    }

    return program_execution;
}
