#include "s21_process_grep_file.h"

void process_file_grep(int flags, const char *pattern, FILE *file, const char *filename, int file_count, int *program_execution)
{
    regex_t regex;

    int regex_flags = REG_EXTENDED;

    if (flags & FLAG_I)
    {
        regex_flags |= REG_ICASE;
    }

    if (regcomp(&regex, pattern, regex_flags) != 0)
    {
        fprintf(stderr, "Недопустимое регулярное выражение: %s\n", pattern);
        *program_execution = 1;
        return;
    }

    char line[MAX_LINE_LENGTH];
    int line_number = 0;        
    int match_count = 0;        
    int file_has_matches = 0; 

    while (fgets(line, sizeof(line), file))
    {
        line_number++;
        int match = regexec(&regex, line, 0, NULL, 0) == 0;

        if ((flags & FLAG_V) ? !match : match)
        {
            if (flags & FLAG_L)
            {
                file_has_matches = 1;
                break;
            }
            if (flags & FLAG_C)
            {
                match_count++;
            }
            else
            {
                if (file_count > 1)
                {
                    printf(VIOLET "%s:\t " RESET, file == stdin ? "-" : filename);
                }
                if (flags & FLAG_N)
                {
                    printf(GREEN "%d:\t" RESET, line_number);
                }
                printf(RED "%s" RESET, line);
            }
        }
    }

    if (flags & FLAG_C)
    {
        if (file_count > 1)
        {
            printf(VIOLET "%s:\t" RESET, file == stdin ? "-" : filename);
        }

        printf(RED "%d\t" RESET "\n", match_count);
    }

    if (flags & FLAG_L && file_has_matches)
    {
        printf(VIOLET "%s\t" RESET "\n", file == stdin ? "-" : filename);
    }

    regfree(&regex);
}
