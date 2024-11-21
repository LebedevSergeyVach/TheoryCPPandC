#include "s21_cat.h"

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
