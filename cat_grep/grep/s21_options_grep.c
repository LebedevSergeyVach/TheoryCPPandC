#include "s21_options_grep.h"

int parse_options(int argc, char *argv[], int *flags, char **pattern, int *program_execution)
{
    static struct option long_options[] = {
        {"regexp", required_argument, 0, 'e'},
        {"ignore-case", no_argument, 0, 'i'},
        {"invert-match", no_argument, 0, 'v'},
        {"count", no_argument, 0, 'c'},
        {"files-with-matches", no_argument, 0, 'l'},
        {"line-number", no_argument, 0, 'n'},
        {"file", required_argument, 0, 'f'},
        {"no-filename", no_argument, 0, 'h'},
        {0, 0, 0, 0}};

    *pattern = NULL;

    int opt;

    while ((opt = getopt_long(argc, argv, "e:ivclnf:h", long_options, NULL)) != -1)
    {
        switch (opt)
        {
        case 'e':
            *flags |= FLAG_E;
            *pattern = optarg;
            break;
        case 'i':
            *flags |= FLAG_I;
            break;
        case 'v':
            *flags |= FLAG_V;
            break;
        case 'c':
            *flags |= FLAG_C;
            break;
        case 'l':
            *flags |= FLAG_L;
            break;
        case 'n':
            *flags |= FLAG_N;
            break;
        case 'h':
            *flags |= FLAG_H;
            break;
        case 'f':
            *flags |= FLAG_F;
            *pattern = read_patterns_from_file(optarg, program_execution);
            break;
        default:
            error_used_command_grep(program_execution, argv[0]);
            break;
        }
    }

    if (*program_execution)
    {
        optind = -1;
    }
    else if (*pattern == NULL && optind < argc)
    {
        *pattern = argv[optind++];
    }

    return optind;
}
