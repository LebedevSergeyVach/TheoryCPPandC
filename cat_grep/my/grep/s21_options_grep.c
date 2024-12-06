#include "s21_options_grep.h"

int parse_options(int argc, char *argv[], int *flags, char **pattern, int *pattern_dynamic, int *program_execution)
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
        {"help", no_argument, 0, 'H'},
        {0, 0, 0, 0}};

    *pattern = NULL;
    *pattern_dynamic = 0;

    int opt;

    while ((opt = getopt_long(argc, argv, "e:ivclnf:hH", long_options, NULL)) != -1)
    {
        switch (opt)
        {
        case 'e':
            *flags |= FLAG_E;

            if (*pattern == NULL)
            {
                size_t len = strlen(optarg);
                *pattern = malloc(len + 1);

                if (*pattern == NULL)
                {
                    fprintf(stderr, RED "Ошибка выделения памяти для шаблона!\n" RESET);
                    *program_execution = 1;
                }

                strcpy(*pattern, optarg);
                *pattern_dynamic = 1;
            }
            else
            {
                char *new_pattern = concat_patterns(*pattern, optarg, program_execution);

                if (new_pattern == NULL)
                {
                    *program_execution = 1;
                }

                free(*pattern);
                *pattern = new_pattern;
            }
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
            read_patterns_from_file(optarg, pattern, program_execution);
            *pattern_dynamic = 1;
            break;
        case 'H':
            *flags |= FLAG_P;
            printf(
                "Инструкция по команде: " GREEN "%s\n\n" 
                BLUE "-e --regexp=pattern        " RESET "Позволяет указать несколько шаблонов для поиска.\n" 
                BLUE "-i --ignore-case           " RESET "Игнорирует регистр при поиске.\n"
                BLUE "-n --line-number           " RESET "Выводит номера строк, содержащих совпадения.\n"
                BLUE "-c --count                 " RESET "Выводит количество строк, соответствующих шаблону, вместо самих строк.\n"
                BLUE "-v --invert-match          " RESET "Инвертирует совпадение, выводит строки, которые не соответствуют шаблону.\n"
                BLUE "-f --file=file             " RESET "Использует шаблоны из файла для поиска.\n"
                BLUE "-l --files-with-matches    " RESET "Выводит только имена файлов, содержащих совпадения, вместо самих строк.\n"
                BLUE "-h --no-filename           " RESET "Не выводит имена файлов перед совпадениями.\n", argv[0]);
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
