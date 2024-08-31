#include <stdio.h>
#include <stdlib.h>

#define COLUMNMAX 100  // столбец
#define ROWNMAX 100    // строка

int input_matrix_static(int row, int column, int matrix[row][column]);
void output_matrix_static(int row, int column, int matrix[row][column]);
int input_matrix_dynamic_one(int row, int column);
int input_matrix_dynamic_two(int row, int column);
int input_matrix_dynamic_three(int row, int column);
void output_matrix_dynamic(int **matrix, int row, int column);

int main() {
    int programm = 0;
    int operating_mode;

    if (scanf("%d", &operating_mode) != 1 || getchar() != '\n') {
        programm = 1;
    } else if (operating_mode == 1 || operating_mode == 2 || operating_mode == 3 || operating_mode == 4) {
        int row, column;

        if (scanf("%d %d", &row, &column) != 2 || getchar() != '\n') {
            programm = 1;

        } else {
            if (operating_mode == 1) {
                if ((row >= 1 && row <= ROWNMAX) && (column >= 1 && column <= COLUMNMAX)) {
                    int matrix[row][column];

                    if (input_matrix_static(row, column, matrix) != 0) {
                        programm = 1;
                    }
                } else {
                    programm = 1;
                }
            } else if (operating_mode == 2) {
                if (input_matrix_dynamic_one(row, column) != 0) {
                    programm = 1;
                }
            } else if (operating_mode == 3) {
                if (input_matrix_dynamic_two(row, column) != 0) {
                    programm = 1;
                }
            } else if (operating_mode == 4) {
                if (input_matrix_dynamic_three(row, column) != 0) {
                    programm = 1;
                }
            }
        }

    } else {
        programm = 1;
    }

    if (programm != 0) {
        printf("n/a");
    }

    return programm;
}

int input_matrix_static(int row, int column, int matrix[row][column]) {
    int programm = 0;

    for (int i = 0; i < row; i++) {
        for (int j = 0; j < column; j++) {
            if (scanf("%d", &matrix[i][j]) != 1) {
                programm = 1;
            }
        }

        if (getchar() != '\n') {
            programm = 1;
        }
    }

    if (programm == 0) {
        output_matrix_static(row, column, matrix);
    }

    return programm;
}

void output_matrix_static(int row, int column, int matrix[row][column]) {
    for (int i = 0; i < row; i++) {
        for (int j = 0; j < column; j++) {
            printf("%d", matrix[i][j]);
            if (j < column - 1) {
                printf(" ");
            }
        }
        if (i < row - 1) {
            printf("\n");
        }
    }
}

int input_matrix_dynamic_one(int row, int column) {
    int **matrix = malloc(row * column * sizeof(int) + row * sizeof(int *));
    int *ptr = (int *)(matrix + row);
    int programm = 0;

    for (int i = 0; i < row; i++) {
        matrix[i] = ptr + column * i;
    }

    for (int i = 0; i < row; i++) {
        for (int j = 0; j < column; j++) {
            if (scanf("%d", &matrix[i][j]) != 1) {
                programm = 1;
            }
        }

        if (getchar() != '\n') {
            programm = 1;
        }
    }

    if (programm == 0) {
        output_matrix_dynamic(matrix, row, column);
    }

    free(matrix);

    return programm;
}

int input_matrix_dynamic_two(int row, int column) {
    int programm = 0;
    int **matrix = malloc(row * sizeof(int *));

    for (int i = 0; i < row; i++) {
        matrix[i] = malloc(column * sizeof(int));
    }

    for (int i = 0; i < row; i++) {
        for (int j = 0; j < column; j++) {
            if (scanf("%d", &matrix[i][j]) != 1) {
                programm = 1;
            }
        }

        if (getchar() != '\n') {
            programm = 1;
        }
    }

    if (programm == 0) {
        output_matrix_dynamic(matrix, row, column);
    }

    for (int i = 0; i < row; i++) {
        free(matrix[i]);
    }

    free(matrix);

    return programm;
}

int input_matrix_dynamic_three(int row, int column) {
    int **matrix = malloc(row * sizeof(int *));
    int *array = malloc(row * column * sizeof(int));
    int programm = 0;

    for (int i = 0; i < row; i++) {
        matrix[i] = array + column * i;
    }

    for (int i = 0; i < row; i++) {
        for (int j = 0; j < column; j++) {
            if (scanf("%d", &matrix[i][j]) != 1) {
                programm = 1;
            }
        }

        if (getchar() != '\n') {
            programm = 1;
        }
    }

    if (programm == 0) {
        output_matrix_dynamic(matrix, row, column);
    }

    free(matrix);
    free(array);

    return programm;
}

void output_matrix_dynamic(int **matrix, int row, int column) {
    for (int i = 0; i < row; i++) {
        for (int j = 0; j < column; j++) {
            printf("%d", matrix[i][j]);
            if (j < column - 1) {
                printf(" ");
            }
        }
        if (i < row - 1) {
            printf("\n");
        }
    }
}