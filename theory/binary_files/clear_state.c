#include "clear_state.h"

int read_record(FILE *file, Record *record);
void write_record(FILE *file, Record *record);
int parse_date(const char *date_str, Record *record);
int compare_dates(Record *rec1, Record *rec2);
void clear_records(const char *filename, Record *start_date, Record *end_date);

int main() {
    int programm = 0;

    char *filename = malloc(MAX_NAME_FILE * sizeof(char));
    char *date_range = malloc(MAX_DATA_FILE * sizeof(char));

    scanf("%100s", filename);
    scanf("%29s", date_range);

    Record start_date, end_date;

    char start_date_str[300], end_date_str[300];

    if (sscanf(date_range, "%299s %299s", start_date_str, end_date_str) != 2) {
        printf("n/a");
        programm = 1;
    } else {
        if (!parse_date(start_date_str, &start_date) || !parse_date(end_date_str, &end_date)) {
            printf("n/a");
            programm = 1;
        } else {
            clear_records(filename, &start_date, &end_date);
        }
    }

    free(filename);
    free(date_range);

    return programm;
}

int read_record(FILE *file, Record *record) {
    int programm = 0;
    programm = fread(record, RECORD_SIZE, 1, file) == 1;

    return programm;
}

void write_record(FILE *file, Record *record) { fwrite(record, RECORD_SIZE, 1, file); }

int parse_date(const char *date_str, Record *record) {
    int programm = 1;
    int day, month, year;

    if (sscanf(date_str, "%d.%d.%d", &day, &month, &year) != 3) {
        programm = 0;
    } else {
        record->day = day;
        record->month = month;
        record->year = year;
    }

    return programm;
}

int compare_dates(Record *rec1, Record *rec2) {
    int programm = 0;

    if (rec1->year != rec2->year) {
        programm = rec1->year - rec2->year;
    } else if (rec1->month != rec2->month) {
        programm = rec1->month - rec2->month;
    } else {
        programm = rec1->day - rec2->day;
    }

    return programm;
}

void clear_records(const char *filename, Record *start_date, Record *end_date) {
    FILE *file = fopen(filename, "rb+");

    if (!file) {
        printf("n/a");
    } else {
        fseek(file, 0, SEEK_END);
        long file_size = ftell(file);
        int num_records = file_size / RECORD_SIZE;

        Record *records = malloc(num_records * RECORD_SIZE);
        if (!records) {
            fclose(file);
            printf("n/a");
        } else {
            fseek(file, 0, SEEK_SET);
            int index = 0;
            Record current_record;
            while (read_record(file, &current_record)) {
                if (compare_dates(&current_record, start_date) < 0 ||
                    compare_dates(&current_record, end_date) > 0) {
                    records[index++] = current_record;
                }
            }

            fclose(file);

            file = fopen(filename, "wb");
            if (!file) {
                free(records);
                printf("n/a");
            } else {
                for (int i = 0; i < index; i++) {
                    read_record(file, &records[i]);
                }

                free(records);
                fclose(file);
            }
        }
    }
}
