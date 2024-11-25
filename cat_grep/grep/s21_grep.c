#include "s21_grep.h"

int main(int argc, char *argv[])
{
    int program_execution = 0;

    int flags = 0;
    char *pattern = NULL;

    int file_start_index = parse_options(argc, argv, &flags, &pattern, &program_execution);

    // Проверка наличия шаблона
    if (pattern == NULL)
    {
        fprintf(stderr, "Требуется шаблон для работы поиска.\n");
        program_execution = 1;
    }

    if (!program_execution)
    {
        // Количество файлов
        int file_count = argc - file_start_index;

        // Обработка файлов или стандартного ввода
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

    if (program_execution)
    {
        printf(RED "ОШИБКА ВЫПОЛЕНИЯ ПРОГРАММЫ GREP\n" RESET);
    }

    return program_execution;
}
