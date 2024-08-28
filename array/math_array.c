#include <stdio.h>

#define NMAX 10

int input(int *buffer, int *length);
void output(const int *buffer, int length);
void output_sum(int sum);
int parity_check(const int *buffer, int length);
int sum_numbers(const int *buffer, int length);
int find_numbers(const int *buffer, int length, int number, int *numbers);

int main() {
    int programm = 0;
    int n, data[NMAX];

    programm = input(data, &n);

    if (programm != 0) {
        printf("n/a");
    } else {
        int parity_checking = parity_check(data, n);

        if (parity_checking != 0) {
            printf("n/a");
            programm = 1;
        } else {
            int sum = sum_numbers(data, n);
            int finf[NMAX];

            output_sum(sum);
            int count = find_numbers(data, n, sum, finf);
            output(finf, count);
        }
    }

    return programm;
}

int input(int *buffer, int *length) {
    int programm = 0;

    if (scanf("%d", length) != 1 || getchar() != '\n' || *length > NMAX || *length <= 0) {
        programm = 1;
    } else {
        for (int *p = buffer; p - buffer < *length; p++) {
            if (scanf("%d", p) != 1) {
                programm = 1;
            }
        }

        if (getchar() != '\n') {
            programm = 1;
        }
    }

    return programm;
}

void output(const int *buffer, int length) {
    for (int i = 0; i < length; i++) {
        printf("%d ", buffer[i]);
    }
}

void output_sum(int sum) { printf("%d\n", sum); }

int parity_check(const int *buffer, int length) {
    int programm = 1;

    for (int i = 0; i < length; i++) {
        if (buffer[i] % 2 == 0) {
            programm = 0;
            break;
        }
    }

    return programm;
}

int sum_numbers(const int *buffer, int length) {
    int sum = 0;

    for (int i = 0; i < length; i++) {
        if (buffer[i] % 2 == 0) {
            sum += buffer[i];
        }
    }

    return sum;
}

int find_numbers(const int *buffer, int length, int number, int *numbers) {
    int count = 0;

    if (number == 0) {
        for (int i = 0; i < length; i++) {
            if (buffer[i] != 0) {
                numbers[count] = buffer[i];
                count++;
            }
        }
    } else {
        for (int i = 0; i < length; i++) {
            if (number >= buffer[i] && buffer[i] != 0) {
                if (number % buffer[i] == 0) {
                    numbers[count] = buffer[i];
                    count++;
                }
            }
        }
    }

    return count;
}
