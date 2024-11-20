#ifndef S21_CAT_H
#define S21_CAT_H

#include <getopt.h>

#include "../common/common.h"
#include "../common/error.h"

#define FLAG_B 0x01
#define FLAG_E 0x02
#define FLAG_N 0x04
#define FLAG_S 0x08
#define FLAG_T 0x10

int parse_options(int argc, char *argv[], int *flags);

#endif
