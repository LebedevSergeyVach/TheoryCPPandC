#include "s21_options_cat.h"

int parse_options(int argc, char *argv[], int *flags) {
  int program_execution = 0;

  static struct option long_options[] = {
      {"number-nonblank", no_argument, 0, 'b'},
      {"number", no_argument, 0, 'n'},
      {"squeeze-blank", no_argument, 0, 's'},
      {"show-nonprinting", no_argument, 0, 'v'},
      {"help", no_argument, 0, 'H'},
      {0, 0, 0, 0}};

  int opt;

  while ((opt = getopt_long(argc, argv, "benstvETH", long_options, NULL)) !=
         -1) {
    switch (opt) {
      case 'b':
        *flags |= FLAG_B;
        break;
      case 'e':
        *flags |= FLAG_E;
        *flags |= FLAG_V;
        break;
      case 'n':
        *flags |= FLAG_N;
        break;
      case 's':
        *flags |= FLAG_S;
        break;
      case 't':
        *flags |= FLAG_V;
        *flags |= FLAG_T;
        break;
      case 'E':
        *flags |= FLAG_E;
        break;
      case 'T':
        *flags |= FLAG_T;
        break;
      case 'v':
        *flags |= FLAG_V;
        break;
      case 'H':
        *flags |= FLAG_P;
        printf(
            "Инструкция по команде: %s\n\n"
            "-b --number-nonblank     Нумерует только непустые строки.\n"
            "-n --number              Нумерует все выходные строки.\n"
            "-s --squeeze-blank       Сжимает несколько смежных пустых строк в "
            "одну.\n"
            "-v --show-nonprinting    Отображает непечатаемые символы, кроме "
            "пробелов и символов новой строки.\n"
            "-t предполагает и -v     Отображает символы табуляции (табы как "
            "^I).\n"
            "-e предполагает и -v     Отображает символы конца строки как $.\n"
            "-T без -v                Отображает символы табуляции (табы как "
            "^I).\n"
            "-E без -v                Отображает символы конца строки как $.\n",
            argv[0]);
        break;
      default:
        error_used_command_cat(&program_execution, argv[0]);
        break;
    }
  }

  return program_execution;
}
