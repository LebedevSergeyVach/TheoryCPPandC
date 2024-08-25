#include <curses.h>
#include <stdio.h>
#include <unistd.h>

// Настройки игры
#define TIME_LAG 150
#define WINSCORE 21
#define PRINT_INSTRUCTION 1  // 0 - не выводить, 1 - выводить
#define WIDHT_FIELD 82
#define HEIGHT_FIELD 27

// Таблица очков
#define PRINT_SCORE_TABLE 1  // 0 - не выводить, 1 - выводить
#define WIDHT_SCORE_TABLE WIDHT_FIELD
#define HEIGHT_SCORE_TABLE 5
#define CENTER_HEIGHT_SCORE_TABLE 3

// Таблица победителя
#define WIDHT_WIN_TABLE WIDHT_FIELD
#define HEIGHT_WIN_TABLE 5
#define CENTER_HEIGHT_WIN_TABLE 3

#define ROCKET_START_Y (HEIGHT_FIELD / 2)

#define BALL_START_X (WIDHT_FIELD / 2) - 1
#define BALL_START_Y (HEIGHT_FIELD / 2) + 1
#define DIRECTION_X_START 1  // -1 - движется влево, 1 - движется вправо
#define DIRECTION_Y_START 1  // -1 - движется вверх, 1 - движется вниз

#define WALL_LEFT 4
#define WALL_RIGHT (WIDHT_FIELD - 3)
#define WALL_TOP 2
#define WALL_BOTTOM (HEIGHT_FIELD - 1)

#define TRUE 1

/*
    Изменить расположение ракетки, если получена соответствующая команда
*/
int move_rocket(int rocket_num, int rocket, char command);
/*
    Сравнить расположение мяча и ракетки по вертикали
*/
int ball_hit_rocket(int ball, int rocket);
/*
    Мяч отскакивает от верхней/нижнюей стенки
*/
int bounce_wall(int direction, int ball);
/*
    Отобразить экран игры (игровое поле и таблица со счетом)
    Аргументы: центр 1-ой ракетки, центр 2-ой ракетки, кордината Х мяча, координата Y мяча, счет 1-ого игрока,
    счет 2-ого игрока
*/
void print_game_field(int center_rocket_one, int center_rocket_two, int ball_x, int ball_y,
                      int score_player_one, int score_player_two);
/*
    Отобразить таблицу со счетом игроков, используется в print_game_field()
    Аргументы: счет 1-ого игрока, счет 2-ого игрока
*/
void print_table(int score_player_one, int score_player_two);
/*
    Метод для вывода победителя игры и счета игроков, используется в main()
    Аргументы: счет 1-ого игрока, счет 2-ого игрока
*/
void print_win_player(int score_player_one, int score_player_two);

int main() {
    int ball_x = BALL_START_X, ball_y = BALL_START_Y;
    int direction_x = DIRECTION_X_START, direction_y = DIRECTION_Y_START;
    int rocket_one_y = ROCKET_START_Y, rocket_two_y = ROCKET_START_Y;
    int score_player_one = 0, score_player_two = 0;

    initscr();

    while (TRUE) {
        refresh();
        timeout(TIME_LAG);

        print_game_field(rocket_one_y, rocket_two_y, ball_x, ball_y, score_player_one, score_player_two);
        char command = getch();

        rocket_one_y = move_rocket(1, rocket_one_y, command);
        rocket_two_y = move_rocket(2, rocket_two_y, command);
        ball_x += direction_x;
        ball_y += direction_y;

        if (direction_x < 0 && ball_x == WALL_LEFT) {
            direction_x *= -1;
            if (ball_hit_rocket(ball_y, rocket_one_y) != 1) {
                score_player_two += 1;
                ball_x = BALL_START_X;
                ball_y = BALL_START_Y;
                rocket_one_y = ROCKET_START_Y;
                rocket_two_y = ROCKET_START_Y;
                continue;
            }
        } else if (direction_x > 0 && ball_x == WALL_RIGHT) {
            direction_x *= -1;
            if (ball_hit_rocket(ball_y, rocket_two_y) != 1) {
                score_player_one += 1;
                ball_x = BALL_START_X;
                ball_y = BALL_START_Y;
                rocket_one_y = ROCKET_START_Y;
                rocket_two_y = ROCKET_START_Y;
                continue;
            }
        }

        direction_y = bounce_wall(direction_y, ball_y);

        if (score_player_one == WINSCORE || score_player_two == WINSCORE) break;
    }

    endwin();
    print_win_player(score_player_one, score_player_two);
}

int move_rocket(int rocket_num, int rocket, char command) {
    if (rocket_num == 1) {
        if ((command == 'a' || command == 'A') && (rocket - 3 > 0)) rocket -= 1;
        if ((command == 'z' || command == 'Z') && (rocket + 2 < HEIGHT_FIELD)) rocket += 1;
    }
    if (rocket_num == 2) {
        if ((command == 'k' || command == 'K') && (rocket - 3 > 0)) rocket -= 1;
        if ((command == 'm' || command == 'M') && (rocket + 2 < HEIGHT_FIELD)) rocket += 1;
    }

    return rocket;
}

int ball_hit_rocket(int ball_y, int rocket_y) {
    if (ball_y == rocket_y - 1 || ball_y == rocket_y || ball_y == rocket_y + 1) {
        return 1;
    }
    return 0;
}

int bounce_wall(int direction, int ball) {
    if (direction < 0 && ball == WALL_TOP)
        direction *= -1;
    else if (direction > 0 && ball == WALL_BOTTOM)
        direction *= -1;

    return direction;
}

void print_game_field(int center_rocket_one, int center_rocket_two, int ball_x, int ball_y,
                      int score_player_one, int score_player_two) {
    clear();

    print_table(score_player_one, score_player_two);

    for (int i = 1; i <= HEIGHT_FIELD; i++) {
        for (int j = 1; j <= WIDHT_FIELD; j++) {
            if (i == ball_y && j == ball_x) {
                printw("O");
            } else if ((j == 3) &&
                       (i == center_rocket_one - 1 || i == center_rocket_one || i == center_rocket_one + 1)) {
                printw("#");
            } else if ((j == WIDHT_FIELD - 2) &&
                       (i == center_rocket_two - 1 || i == center_rocket_two || i == center_rocket_two + 1)) {
                printw("#");
            } else if (i == 1 || i == HEIGHT_FIELD) {
                printw("-");
            } else if ((j == 1 || j == WIDHT_FIELD || j == (WIDHT_FIELD - 2) / 2) && (i != HEIGHT_FIELD)) {
                printw("|");
            } else {
                printw(" ");
            }
        }

        printw("\n");
    }

    if (PRINT_INSTRUCTION) {
        printw("Player One: a/z. Player Two: k/m\n");
    }
}

void print_table(int score_player_one, int score_player_two) {
    for (int i = 1; i <= HEIGHT_SCORE_TABLE; i++) {
        if (i == 3) {
            printw("|                  %02d                  |                    %02d                   |",
                   score_player_one, score_player_two);
        }

        for (int j = 1; j <= WIDHT_SCORE_TABLE; j++) {
            if (i == 1 || i == 5) {
                printw("-");
            } else if ((j == 1 || j == 82 || j == 40) && (i != 3)) {
                printw("|");
            } else if (i == 3) {
                continue;
            } else {
                printw(" ");
            }
        }

        printw("\n");
    }
}

void print_win_player(int score_player_one, int score_player_two) {
    clear();

    for (int i = 1; i <= HEIGHT_SCORE_TABLE; i++) {
        if (score_player_one > score_player_two) {
            if (i == CENTER_HEIGHT_WIN_TABLE) {
                printf(
                    "|                     Первый игрок победил со счетом %02d : %02d                     |",
                    score_player_one, score_player_two);
            }
        } else {
            if (i == CENTER_HEIGHT_WIN_TABLE) {
                printf(
                    "|                     Второй игрок победил со счетом %02d : %02d                     |",
                    score_player_one, score_player_two);
            }
        }

        for (int j = 1; j <= WIDHT_SCORE_TABLE; j++) {
            if (i == 1 || i == 5) {
                printf("-");
            } else if ((j == 1 || j == WIDHT_WIN_TABLE) && (i != CENTER_HEIGHT_WIN_TABLE)) {
                printf("|");
            } else if (i == CENTER_HEIGHT_WIN_TABLE) {
                continue;
            } else {
                printf(" ");
            }
        }

        printf("\n");
    }

    printf("\n");
}
