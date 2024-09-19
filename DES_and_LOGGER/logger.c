#include "logger.h"

FILE* log_init(char* filename);
int logcat(FILE* log_file, char* message, log_level level);
int log_close(FILE* log_file);

void getTimeIsNow(TimeIsNow* time_now) {
    time_t current_time;
    time(&current_time);

    struct tm* local_time = localtime(&current_time);

    time_now->hours = local_time->tm_hour;
    time_now->minuts = local_time->tm_min;
    time_now->seconds = local_time->tm_sec;
}

void getDataIsNow(DataIsNow* data_now) {
    time_t current_time;
    time(&current_time);

    struct tm* local_time = localtime(&current_time);

    data_now->days = local_time->tm_mday;
    data_now->months = local_time->tm_mon;
    data_now->years = local_time->tm_year + 1900;
}

FILE* log_init(char* filename) {
    FILE* log_file = fopen(filename, "a");

    return log_file;
}

int logcat(FILE* log_file, char* message, log_level level) {
    int programm = 0;

    if (log_file == NULL) {
        programm = 1;
    } else {
        DataIsNow data;
        TimeIsNow time;

        getTimeIsNow(&time);
        getDataIsNow(&data);

        // time_t now = time(NULL);
        // char* time_str = ctime(&now);
        // time_str[strlen(time_str) - 1] = '\0';

        const char* level_str;
        switch (level) {
            case DEBUG:
                level_str = "DEBUG";
                break;
            case INFO:
                level_str = "INFO";
                break;
            case WARNING:
                level_str = "WARNING";
                break;
            case ERROR:
                level_str = "ERROR";
                break;
            default:
                level_str = "UNKNOWN";
                break;
        }

        // fprintf(log_file, "[%s] %s: %s \n", time_str, level_str, message);
        fprintf(log_file, "[%02d:%02d:%04d - %02d:%02d:%02d] %s: %s \n", data.days, data.months, data.years,
                time.hours, time.minuts, time.seconds, level_str, message);
        fflush(log_file);

        return 0;
    }

    return programm;
}

int log_close(FILE* log_file) {
    int programm = 0;
    if (log_file == NULL) {
        programm = 1;
    } else {
        fclose(log_file);
    }

    return programm;
}
