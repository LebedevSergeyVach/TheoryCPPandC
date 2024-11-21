#include "s21_process_cat_file.h"

void print_line(const char *line, int number, int is_nonblank)
{
    if (is_nonblank)
    {
        printf("%6d\t", number);
    }
    printf("%s", line);
}

void process_file(FILE *file, int flags)
{
    char line[MAX_LINE_LENGTH];
    int line_number = 0;
    int prev_line_empty = 0;

    while (fgets(line, MAX_LINE_LENGTH, file))
    {
        int is_nonblank = (line[0] != '\n');
        int is_empty = (line[0] == '\n');

        if (flags & 0x08)
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

        if (flags & 0x02)
        {
            if (line[strlen(line) - 1] == '\n')
            {
                line[strlen(line) - 1] = '$';
                strcat(line, "\n");
            }
        }

        if (flags & 0x10)
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

        if (flags & 0x01)
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
        else if (flags & 0x04)
        {
            print_line(line, ++line_number, 1);
        }
        else
        {
            print_line(line, 0, 0);
        }
    }
}
