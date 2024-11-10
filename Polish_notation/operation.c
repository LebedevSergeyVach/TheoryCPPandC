#include "operation.h"

int is_operator(char ch) { return (ch == '+' || ch == '-' || ch == '*' || ch == '/'); }

int precedence(char ch) {
    if (ch == '+' || ch == '-') return 1;
    if (ch == '*' || ch == '/') return 2;
    return 0;
}

void plot_function(char *expression) {
    char postfix[MAX_SIZE];
    infix_to_postfix(expression, postfix);
    char graph[HEIGHT][WIDTH];
    for (int i = 0; i < HEIGHT; i++) {
        for (int j = 0; j < WIDTH; j++) {
            graph[i][j] = '.';
        }
    }

    double x_min = 0;
    double x_max = 4 * M_PI;
    double y_min = -1.0;
    double y_max = 1.0;
    double x_step = (x_max - x_min) / (WIDTH - 1);
    double y_step = (y_max - y_min) / (HEIGHT - 1);

    for (int j = 0; j < WIDTH; j++) {
        double x = x_min + j * x_step;
        double y = evaluate_postfix(postfix, x);
        int y_index = (int)((y - y_min) / y_step);
        if (y_index >= 0 && y_index < HEIGHT) {
            graph[y_index][j] = '*';
        }
    }

    for (int i = 0; i < HEIGHT; i++) {
        for (int j = 0; j < WIDTH; j++) {
            printf("%c", graph[i][j]);
        }
        printf("\n");
    }
}
