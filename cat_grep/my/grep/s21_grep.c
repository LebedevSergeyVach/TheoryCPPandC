#include "s21_grep.h"

int main(int argc, char *argv[])
{
    int program_execution = 0;

    int flags = 0;
    char *pattern = NULL;
    int pattern_dynamic = 0;

    int file_start_index = parse_options(argc, argv, &flags, &pattern, &pattern_dynamic, &program_execution);

    if (pattern == NULL && !(flags & FLAG_P))
    {
        fprintf(stderr, RED "Требуется шаблон для работы поиска.\n" RESET);
        program_execution = 1;
    }

    if (!program_execution && !(flags & FLAG_P))
    {
        int file_count = argc - file_start_index;

        if (file_start_index == argc)
        {
            process_file_grep(flags, pattern, stdin, "-", file_count, &program_execution);
        }
        else
        {
            for (int i = file_start_index; i < argc; i++)
            {
                FILE *file = fopen(argv[i], "r");
                if (file == NULL)
                {
                    error_check_file_exists(&program_execution, argc, argv);
                    continue;
                }

                process_file_grep(flags, pattern, file, argv[i], file_count, &program_execution);

                fclose(file);
            }
        }
    }

    if (pattern != NULL && pattern_dynamic)
    {
        free(pattern);
    }

    if (program_execution)
    {
        printf(RED "ОШИБКА ВЫПОЛЕНИЯ ПРОГРАММЫ GREP\n" RESET);
    }

    return program_execution;
}
