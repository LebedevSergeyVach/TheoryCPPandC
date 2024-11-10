#ifndef CLEAR_STATE_H
#define CLEAR_STATE_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define RECORD_SIZE sizeof(Record)
#define MAX_NAME_FILE 101
#define MAX_DATA_FILE 30

typedef struct {
    int year;
    int month;
    int day;
    int hour;
    int minute;
    int second;
    int status;
    int code;
} Record;

#endif
