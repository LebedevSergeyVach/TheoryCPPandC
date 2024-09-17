#include <stdio.h>

void spiral(int number);
void print_matrix(int number, int matrix[number][number]);

int main() {
    int programm = 0;
    int number;

    if (scanf("%d", &number) != 1 || getchar() != '\n' || number < 1) {
        programm = 1;
    } else {
        spiral(number);
    }

    if (programm != 0) {
        printf("n/a");
    }

    return programm;
}

void spiral(int number) {
    int left = 0, right = number - 1, up = 0, down = number - 1;
    int count = 1;

    int matrix[number][number];

    while (count <= number * number) {
        for (int i = left; i <= right; i++) {
            matrix[up][i] = count++;
        }
        up++;

        for (int i = up; i <= down; i++) {
            matrix[i][right] = count++;
        }
        right--;

        for (int i = right; i >= left; i--) {
            matrix[down][i] = count++;
        }
        down--;

        for (int i = down; i >= up; i--) {
            matrix[i][left] = count++;
        }
        left++;
    }

    print_matrix(number, matrix);
}

void print_matrix(int number, int matrix[number][number]) {
    for (int i = 0; i < number; i++) {
        for (int j = 0; j < number; j++) {
            printf("%d", matrix[i][j]);

            if (j < number - 1) printf(" ");
        }

        if (i < number - 1) printf("\n");
    }
}
