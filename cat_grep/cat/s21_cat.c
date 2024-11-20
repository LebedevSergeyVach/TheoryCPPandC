#include "s21_cat.h"

int parse_options(int argc, char *argv[], int *flags);

int main(int argc, char *argv[])
{
    int program_execution = 0;

    int flags = 0;
    program_execution = parse_options(argc, argv, &flags);

    if (!program_execution)
    {
        if (optind == argc)
        {
            process_file(stdin, flags);
        }
        else
        {
            for (int i = optind; i < argc; i++)
            {
                FILE *file = fopen(argv[i], "r");
                if (file == NULL)
                {
                    error_check_file_exists(&program_execution, argc, argv);
                    continue;
                }
                process_file(file, flags);
                fclose(file);
            }
        }
    }

    if (program_execution)
    {
        printf("ОШИБКА ВЫПОЛЕНИЯ ПРОГРАММЫ CAT\n");
    }

    return program_execution;
}

int parse_options(int argc, char *argv[], int *flags)
{
    int program_execution = 0;

    static struct option long_options[] = {
        {"number-nonblank", no_argument, 0, 'b'},
        {"number", no_argument, 0, 'n'},
        {"squeeze-blank", no_argument, 0, 's'},
        {0, 0, 0, 0}};

    int flag;

    while ((flag = getopt_long(argc, argv, "benstET", long_options, NULL)) != -1)
    {
        switch (flag)
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
        default:
            error_used_command(&program_execution, argv[0]);
            break;
        }
    }

    return program_execution;
}
