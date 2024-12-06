#include "s21_process_cat_file.h"

void print_char(unsigned char uc, int flags, int *line_number,
                int *in_nonblank_line, int *new_line_start) {
  int printed = 0;

  if (flags & FLAG_B) {
    if (uc == '\n') {
      *in_nonblank_line = 0;
    } else if (!*in_nonblank_line) {
      *in_nonblank_line = 1;
      printf("%6d\t", ++(*line_number));
    }
  } else if (flags & FLAG_N) {
    if (*new_line_start) {
      printf("%6d\t", ++(*line_number));
      *new_line_start = 0;
    }
    if (uc == '\n') {
      *new_line_start = 1;
    }
  }

  if (flags & FLAG_E && uc == '\n') {
    printf("$");
  }

  if (flags & FLAG_T && uc == '\t') {
    printf("^I");
    printed = 1;
  }

  if (flags & FLAG_V && !printed) {
    if (uc < 32 && uc != '\t' && uc != '\n') {
      printf("^%c", uc + 64);
      printed = 1;
    } else if (uc == 127) {
      printf("^?");
      printed = 1;
    } else if (uc > 127) {
      unsigned char high_byte = uc - 128;
      if (high_byte < 32 && high_byte != '\t' && high_byte != '\n') {
        printf("M-^%c", high_byte + 64);
      } else {
        printf("M-%c", high_byte);
      }

      printed = 1;
    }
  }

  if (!printed) {
    putchar(uc);
  }
}

void process_file_cat(FILE *file, int flags) {
  int c;

  int line_number = 0;
  int prev_line_empty = 0;
  int in_nonblank_line = 0;
  int skip_newline = 0;
  int new_line_start = 1;

  while ((c = fgetc(file)) != EOF) {
    unsigned char uc = (unsigned char)c;

    if (flags & FLAG_S) {
      if (uc == '\n') {
        if (prev_line_empty) {
          skip_newline = 1;
          continue;
        }

        prev_line_empty = 1;
      } else {
        if (skip_newline) {
          if (flags & FLAG_E) {
            putchar('$');
          }

          putchar('\n');
          skip_newline = 0;
        }

        prev_line_empty = 0;
      }
    }

    print_char(uc, flags, &line_number, &in_nonblank_line, &new_line_start);
  }
}
