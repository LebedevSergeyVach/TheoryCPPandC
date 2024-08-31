#include <curses.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#define HEIGHT 25
#define WIDTH 80

#define LIVELY 'O'
#define DEAD ' '

#define TRUE 1

/*
    КОМПИЛИРОВАНИЕ И ЗАПУСК:
    clear && gcc -lcurses game_of_life.c && ./a.out < start_game_of_life/glutton.txt
*/

/*
    Функция для подсчета количества живых соседей клетки
*/
int count_neighbors(char matrix[HEIGHT][WIDTH], int x, int y);
/*
    Функция для обновления состояния поля
*/
void update_matrix(char matrix[HEIGHT][WIDTH], char new_matrix[HEIGHT][WIDTH]);
/*
    Функция для инициализации поля из stdin
*/
void initialize_matrix_from_stdin(char matrix[HEIGHT][WIDTH]);
/*
    Функция для проверки равенства двух матриц - конец игры!
*/
int stop_game(char matrix[HEIGHT][WIDTH], char new_matrix[HEIGHT][WIDTH]);
/*
    Функция изменения скорости
*/
void speed_mode(char command, int *speed);
/*
    Функция вывода матрицы (игрвого поля) на экран
*/
void print_game_field(char matrix[HEIGHT][WIDTH]);
/*
    Функция вывода конца игры
*/
void print_game_over();

int main() {
    char matrix_game[HEIGHT][WIDTH];
    char new_matrix_game[HEIGHT][WIDTH];

    int speed_game = 300000;

    initialize_matrix_from_stdin(matrix_game);

    initscr();
    noecho();
    timeout(0);

    while (TRUE) {
        refresh();

        char command = getch();
        speed_mode(command, &speed_game);

        print_game_field(matrix_game);
        update_matrix(matrix_game, new_matrix_game);

        if (stop_game(matrix_game, new_matrix_game)) {
            break;
        }

        memcpy(matrix_game, new_matrix_game, sizeof(matrix_game));

        usleep(speed_game);
    }

    endwin();

    print_game_over(matrix_game);

    return 0;
}

int count_neighbors(char matrix[HEIGHT][WIDTH], int x, int y) {
    int count = 0;
    for (int i = -1; i <= 1; i++) {
        for (int j = -1; j <= 1; j++) {
            if (i == 0 && j == 0) continue;  // Пропускаем саму клетку

            int nx = (x + i + HEIGHT) % HEIGHT;  // Обрабатываем замкнутое поле
            int ny = (y + j + WIDTH) % WIDTH;

            if (matrix[nx][ny] == LIVELY) {
                count++;
            }
        }
    }
    return count;
}

void update_matrix(char matrix[HEIGHT][WIDTH], char new_matrix[HEIGHT][WIDTH]) {
    for (int i = 0; i < HEIGHT; i++) {
        for (int j = 0; j < WIDTH; j++) {
            int neighbors = count_neighbors(matrix, i, j);
            if (matrix[i][j] == LIVELY) {
                new_matrix[i][j] = (neighbors == 2 || neighbors == 3) ? LIVELY : DEAD;
            } else {
                new_matrix[i][j] = (neighbors == 3) ? LIVELY : DEAD;
            }
        }
    }
}

void initialize_matrix_from_stdin(char matrix[HEIGHT][WIDTH]) {
    for (int i = 0; i < HEIGHT; i++) {
        for (int j = 0; j < WIDTH; j++) {
            matrix[i][j] = DEAD;
        }
    }
    char line[WIDTH + 2];
    for (int i = 0; i < HEIGHT && fgets(line, sizeof(line), stdin); i++) {
        for (int j = 0; j < WIDTH && line[j] != '\0'; j++) {
            if (line[j] == LIVELY) {
                matrix[i][j] = LIVELY;
            }
        }
    }

    stdin = freopen("/dev/tty", "r", stdin);
}

int stop_game(char matrix[HEIGHT][WIDTH], char new_matrix[HEIGHT][WIDTH]) {
    int programm = 1;

    for (int i = 0; i < HEIGHT; i++) {
        for (int j = 0; j < WIDTH; j++) {
            if (matrix[i][j] != new_matrix[i][j]) {
                programm = 0;
            }
        }
    }
    return programm;
}

void speed_mode(char command, int *speed) {
    if (command == '1') {
        *speed = 300000;
    } else if (command == '2') {
        *speed = 200000;
    } else if (command == '3') {
        *speed = 100000;
    } else if (command == '4') {
        *speed = 50000;
    } else if (command == '5') {
        *speed = 25000;
    }
}

void print_game_field(char matrix[HEIGHT][WIDTH]) {
    clear();

    for (int i = 0; i < HEIGHT; i++) {
        for (int j = 0; j < WIDTH; j++) {
            printw("%c", matrix[i][j]);
        }
        if (i < HEIGHT) {
            printw("\n");
        }
    }
}

void print_game_over() {
    clear();
    printf("ИГРА ОКОНЧЕНО!\n");
}
