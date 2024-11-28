#include "s21_read_and_combination_patterns.h"

char *concat_patterns(const char *pattern1, const char *pattern2, int *program_execution)
{
    size_t len1 = (pattern1 != NULL) ? strlen(pattern1) : 0;
    size_t len2 = strlen(pattern2);

    char *result = malloc(len1 + len2 + 2);

    if (result == NULL)
    {
        fprintf(stderr, RED "Ошибка выделения памяти для шаблона!\n" RESET);
        *program_execution = 1;
    }

    if (!*program_execution)    
    {
        if (pattern1 != NULL)
        {
            strcpy(result, pattern1);
            strcat(result, "|");
        }
        else
        {
            result[0] = '\0';
        }

        strcat(result, pattern2);
    }

    if (*program_execution)
    {
        free(result);
        result = NULL;
    }

    return result;
}
