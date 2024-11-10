#ifndef LOGGER_H
#define LOGGER_H

#include <string.h>
#include <stdio.h>
#include <time.h>

typedef enum {
    DEBUG,
    INFO,
    WARNING,
    ERROR,
} log_level;

typedef struct TimeIsNow {
    int hours, minuts, seconds;
} TimeIsNow;

typedef struct DataIsNow {
    int days, months, years;
} DataIsNow;

FILE* log_init(char* filename);
int logcat(FILE* log_file, char* message, log_level level);
int log_close(FILE* log_file);

void getTimeIsNow(TimeIsNow* time_now);
void getDataIsNow(DataIsNow* data_now);

#endif
