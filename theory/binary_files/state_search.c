#include "state_search.h"

int read_record(FILE *file, Record *record);
int parse_date(const char *date_str, Record *record);
int search_record(const char *filename, const char *date_str);

int main() {
    int programm = 0;

    char *filename = malloc(MAX_NAME_FILE * sizeof(char));
    char *date_str = malloc(MAX_DATA_FILE * sizeof(char));

    scanf("%100s", filename);
    scanf("%10s", date_str);

    programm = search_record(filename, date_str);

    if (programm != 0) {
        printf("n/a");
    }

    free(filename);
    free(date_str);

    return programm;
}

int read_record(FILE *file, Record *record) { return fread(record, RECORD_SIZE, 1, file) == 1; }

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

int search_record(const char *filename, const char *date_str) {
    int programm = 1;

    FILE *file = fopen(filename, "rb");

    if (file) {
        Record search_criteria, current_record;
        if (parse_date(date_str, &search_criteria)) {
            while (read_record(file, &current_record)) {
                if (current_record.year == search_criteria.year &&
                    current_record.month == search_criteria.month &&
                    current_record.day == search_criteria.day) {
                    printf("%d", current_record.code);
                    programm = 0;
                    break;
                }
            }
        } else {
            programm = 1;
        }
        fclose(file);
    } else {
        programm = 1;
    }

    return programm;
}
