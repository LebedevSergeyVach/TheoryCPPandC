#include "s21_read_patterns_from_file.h"

void read_patterns_from_file(const char *filename, char **pattern,
                             int *program_execution) {
  FILE *file = fopen(filename, "r");
  if (file == NULL) {
    fprintf(stderr, "Файла с шаблонами `%s` не существует или недоступен.\n",
            filename);

    *program_execution = 1;
  }

  if (!*program_execution) {
    *pattern = NULL;
    char line[MAX_LINE_LENGTH];

    while (fgets(line, sizeof(line), file)) {
      size_t len = strlen(line);

      if (line[len - 1] == '\n') {
        line[len - 1] = '\0';
      }

      if (*pattern == NULL) {
        *pattern = malloc(len + 1);

        if (*pattern == NULL) {
          fclose(file);

          fprintf(stderr, "Ошибка выделения памяти для шаблона!\n");
          *program_execution = 1;

          break;
        }

        strcpy(*pattern, line);
      } else {
        char *new_patterns = realloc(*pattern, strlen(*pattern) + len + 2);

        if (new_patterns == NULL) {
          free(*pattern);
          fclose(file);

          fprintf(stderr, "Ошибка выделения памяти для шаблона!\n");
          *program_execution = 1;

          break;
        }

        *pattern = new_patterns;

        strcat(*pattern, "|");
        strcat(*pattern, line);
      }
    }

    fclose(file);
  }
}
