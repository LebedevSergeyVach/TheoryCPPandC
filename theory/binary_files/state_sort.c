#include "state_sort.h"

int read_record(FILE *file, Record *record);
void write_record(FILE *file, Record *record);
int compare_records(const void *a, const void *b);
void sort_file(const char *filename);
void print_file(const char *filename);
void add_record(const char *filename, Record *new_record);

int main() {
    int programm = 0;
    int operation_mode;

    char *name_file = malloc(MAX_NAME_FILE * sizeof(char));
    scanf("%100s", name_file);

    while (scanf("%d", &operation_mode) || getchar() != '\n') {
        if (operation_mode == 0) {
            print_file(name_file);
        } else if (operation_mode == 1) {
            sort_file(name_file);
            print_file(name_file);
        } else if (operation_mode == 2) {
            Record new_record;

            scanf("%d %d %d %d %d %d %d %d", &new_record.year, &new_record.month, &new_record.day,
                  &new_record.hour, &new_record.minute, &new_record.second, &new_record.status,
                  &new_record.code);

            add_record(name_file, &new_record);
            sort_file(name_file);
            print_file(name_file);
        } else if (operation_mode == -1) {
            break;
        } else {
            programm = -1;
        }

        if (programm != 0) {
            printf("n/a\n");
        }
    }

    free(name_file);

    return programm;
}

int read_record(FILE *file, Record *record) { return fread(record, RECORD_SIZE, 1, file) == 1; }

void write_record(FILE *file, Record *record) { fwrite(record, RECORD_SIZE, 1, file); }

int compare_records(const void *a, const void *b) {
    Record *rec1 = (Record *)a;
    Record *rec2 = (Record *)b;

    if (rec1->year != rec2->year) return rec1->year - rec2->year;
    if (rec1->month != rec2->month) return rec1->month - rec2->month;
    if (rec1->day != rec2->day) return rec1->day - rec2->day;
    if (rec1->hour != rec2->hour) return rec1->hour - rec2->hour;
    if (rec1->minute != rec2->minute) return rec1->minute - rec2->minute;
    return rec1->second - rec2->second;
}

void sort_file(const char *filename) {
    FILE *file = fopen(filename, "rb+");
    if (!file) {
        printf("n/a\n");
    } else {
        fseek(file, 0, SEEK_END);
        long file_size = ftell(file);
        int num_records = file_size / RECORD_SIZE;

        Record *records = malloc(num_records * RECORD_SIZE);
        if (!records) {
            fclose(file);
            printf("n/a\n");
        } else {
            fseek(file, 0, SEEK_SET);
            for (int i = 0; i < num_records; i++) {
                read_record(file, &records[i]);
            }

            qsort(records, num_records, RECORD_SIZE, compare_records);

            fseek(file, 0, SEEK_SET);
            for (int i = 0; i < num_records; i++) {
                write_record(file, &records[i]);
            }

            free(records);
            fclose(file);
        }
    }
}

void print_file(const char *filename) {
    FILE *file = fopen(filename, "rb");
    if (!file) {
        printf("n/a\n");
    } else {
        Record record;
        while (read_record(file, &record)) {
            printf("%d %d %d %d %d %d %d %d\n", record.year, record.month, record.day, record.hour,
                   record.minute, record.second, record.status, record.code);
        }

        fclose(file);
    }
}

void add_record(const char *filename, Record *new_record) {
    FILE *file = fopen(filename, "ab");
    if (!file) {
        printf("n/a\n");
    } else {
        write_record(file, new_record);
        fclose(file);
    }
}
