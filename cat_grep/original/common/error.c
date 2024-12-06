#include "error.h"

void error_used_command_cat(int *program_execution, const char *name) {
  fprintf(stderr,
          "Неверное использование команды.\nИспользуйте: "
          "%s -[benstvET / --help] [file]\n",
          name);

  *program_execution = 1;
}

void error_used_command_grep(int *program_execution, const char *name) {
  fprintf(stderr,
          "Неверное использование команды.\nИспользуйте: "
          "%s -[-e pattern] -[-p file_patterns] [-ivclnh / --help] [file]\n",
          name);

  *program_execution = 1;
}

void error_check_file_exists(int *program_execution, int argc, char *argv[]) {
  for (int i = optind; i < argc; i++) {
    if (access(argv[i], F_OK) == -1) {
      fprintf(stderr, "Файл '%s' не существует или недоступен.\n", argv[i]);
      *program_execution = 1;

      break;
    }
  }
}
