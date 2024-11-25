#include "s21_process_cat_file.h"

void print_line(const char *line, int number, int is_nonblank)
{
    if (is_nonblank)
    {
        printf(BLUE "%6d:\t" RESET, number);
    }
    printf("%s", line);
}

void process_file_cat(FILE *file, int flags)
{
    char line[MAX_LINE_LENGTH];
    int line_number = 0;
    int prev_line_empty = 0;

    while (fgets(line, MAX_LINE_LENGTH, file))
    {
        int is_nonblank = (line[0] != '\n');
        int is_empty = (line[0] == '\n');

        if (flags & FLAG_S)
        {
            if (is_empty)
            {
                if (prev_line_empty)
                {
                    continue;
                }
                prev_line_empty = 1;
            }
            else
            {
                prev_line_empty = 0;
            }
        }

        if (flags & FLAG_E)
        {
            if (line[strlen(line) - 1] == '\n')
            {
                line[strlen(line) - 1] = '$';
                strcat(line, "\n");
            }
        }

        if (flags & FLAG_T)
        {
            for (char *p = line; *p; ++p)
            {
                if (*p == '\t')
                {
                    memmove(p + 2, p + 1, strlen(p + 1) + 1);
                    *p = '^';
                    *(++p) = 'I';
                }
                else if (*p == ' ' && *(p + 1) == ' ' && *(p + 2) == ' ' && *(p + 3) == ' ')
                {
                    memmove(p + 2, p + 4, strlen(p + 4) + 1);
                    *p = '^';
                    *(++p) = 'I';
                }
            }
        }

        if (flags & FLAG_V)
        {
            for (char *p = line; *p; ++p)
            {
                unsigned char uc = (unsigned char)*p;
                
                if (uc < 32 && uc != '\t' && uc != '\n')
                {
                    *p = uc + 64;
                    memmove(p + 1, p, strlen(p) + 1);
                    *p = '^';
                }
                else if (uc == 127)
                {
                    *p = '?';
                    memmove(p + 1, p, strlen(p) + 1);
                    *p = '^';
                }
                else if (uc > 127)
                {
                    *p = uc - 128;
                    memmove(p + 1, p, strlen(p) + 1);
                    *p = 'M';
                    *(++p) = '-';
                }
            }
        }

        if (flags & FLAG_B)
        {
            if (is_nonblank)
            {
                print_line(line, ++line_number, 1);
            }
            else
            {
                print_line(line, 0, 0);
            }
        }
        else if (flags & FLAG_N)
        {
            print_line(line, ++line_number, 1);
        }
        else
        {
            print_line(line, 0, 0);
        }
    }
}
