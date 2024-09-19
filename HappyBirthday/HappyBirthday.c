#include <stdio.h>

#define SYMBOL_FOR_LETTERS '@'
#define SYMBOL_SPACE "  "

#define ROW 7
#define COLUMN 7

#define ROW_SMILE 12
#define COLUMN_SMILE 16

#define RESET "\033[0m"
#define BLACK "\033[30m"
#define RED "\033[31m"
#define GREEN "\033[32m"
#define YELLOW "\033[33m"
#define BLUE "\033[34m"
#define MAGENTA "\033[35m"
#define CYAN "\033[36m"
#define WHITE "\033[37m"

void outputMatrix(int column, char matrix[COLUMN], const char *color);
void outputMatrixSmile(int column, char matrix[COLUMN_SMILE], const char *color);

void initializeMatrices(char matrix_c[ROW][COLUMN], char matrix_d[ROW][COLUMN], char matrix_n[ROW][COLUMN],
                        char matrix_e[ROW][COLUMN], char matrix_m[ROW][COLUMN], char matrix_r[ROW][COLUMN],
                        char matrix_o[ROW][COLUMN], char matrix_zh[ROW][COLUMN], char matrix_i[ROW][COLUMN],
                        char matrix_ya[ROW][COLUMN], char matrix_w[ROW][COLUMN], char matrix_smile[ROW_SMILE][COLUMN_SMILE]);

int main()
{
    char matrix_c[ROW][COLUMN];
    char matrix_d[ROW][COLUMN];
    char matrix_n[ROW][COLUMN];
    char matrix_e[ROW][COLUMN];
    char matrix_m[ROW][COLUMN];
    char matrix_r[ROW][COLUMN];
    char matrix_o[ROW][COLUMN];
    char matrix_zh[ROW][COLUMN];
    char matrix_i[ROW][COLUMN];
    char matrix_ya[ROW][COLUMN];
    char matrix_w[ROW][COLUMN];
    char matrix_smile[ROW_SMILE][COLUMN_SMILE];

    initializeMatrices(matrix_c, matrix_d, matrix_n, matrix_e, matrix_m, matrix_r, matrix_o, matrix_zh, matrix_i, matrix_ya, matrix_w, matrix_smile);

    printf("\n");

    for (int i = 0; i < ROW; i++)
    {
        outputMatrix(COLUMN, matrix_c[i], RED);
        printf("%s%s%s", SYMBOL_SPACE, SYMBOL_SPACE, SYMBOL_SPACE);
        outputMatrix(COLUMN, matrix_d[i], GREEN);
        printf("%s", SYMBOL_SPACE);
        outputMatrix(COLUMN, matrix_n[i], YELLOW);
        printf("%s", SYMBOL_SPACE);
        outputMatrix(COLUMN, matrix_e[i], BLUE);
        printf("%s", SYMBOL_SPACE);
        outputMatrix(COLUMN, matrix_m[i], MAGENTA);
        printf("\n");
    }

    printf("\n");

    for (int i = 0; i < ROW; i++)
    {
        outputMatrix(COLUMN, matrix_r[i], CYAN);
        printf("%s", SYMBOL_SPACE);
        outputMatrix(COLUMN, matrix_o[i], WHITE);
        printf("%s", SYMBOL_SPACE);
        outputMatrix(COLUMN, matrix_zh[i], RED);
        printf("%s", SYMBOL_SPACE);
        outputMatrix(COLUMN, matrix_d[i], GREEN);
        printf("%s", SYMBOL_SPACE);
        outputMatrix(COLUMN, matrix_e[i], YELLOW);
        printf("%s", SYMBOL_SPACE);
        outputMatrix(COLUMN, matrix_n[i], BLUE);
        printf("%s", SYMBOL_SPACE);
        outputMatrix(COLUMN, matrix_i[i], MAGENTA);
        printf("%s", SYMBOL_SPACE);
        outputMatrix(COLUMN, matrix_ya[i], CYAN);
        printf("%s%s", SYMBOL_SPACE, SYMBOL_SPACE);
        outputMatrix(COLUMN, matrix_w[i], WHITE);
        printf("\n");
    }

    printf("\n");

    for (int i = 0; i < ROW_SMILE; i++)
    {
        outputMatrixSmile(COLUMN_SMILE, matrix_smile[i], YELLOW);
        printf("%s%s%s", SYMBOL_SPACE, SYMBOL_SPACE, SYMBOL_SPACE);
        outputMatrixSmile(COLUMN_SMILE, matrix_smile[i], YELLOW);
        printf("%s%s%s", SYMBOL_SPACE, SYMBOL_SPACE, SYMBOL_SPACE);
        outputMatrixSmile(COLUMN_SMILE, matrix_smile[i], YELLOW);
        printf("%s%s%s", SYMBOL_SPACE, SYMBOL_SPACE, SYMBOL_SPACE);
        outputMatrixSmile(COLUMN_SMILE, matrix_smile[i], YELLOW);
        printf("%s%s%s", SYMBOL_SPACE, SYMBOL_SPACE, SYMBOL_SPACE);
        printf("\n");
    }

    return 0;
}

void outputMatrix(int column, char matrix[COLUMN], const char *color)
{
    for (int j = 0; j < column; j++)
    {
        printf("%s%c", color, matrix[j]);
    }
    printf(RESET);
}

void outputMatrixSmile(int column, char matrix[COLUMN_SMILE], const char *color)
{
    for (int j = 0; j < column; j++)
    {
        printf("%s%c", color, matrix[j]);
    }
    printf(RESET);
}

void initializeMatrices(char matrix_c[ROW][COLUMN], char matrix_d[ROW][COLUMN], char matrix_n[ROW][COLUMN],
                        char matrix_e[ROW][COLUMN], char matrix_m[ROW][COLUMN], char matrix_r[ROW][COLUMN],
                        char matrix_o[ROW][COLUMN], char matrix_zh[ROW][COLUMN], char matrix_i[ROW][COLUMN],
                        char matrix_ya[ROW][COLUMN], char matrix_w[ROW][COLUMN], char matrix_smile[ROW_SMILE][COLUMN_SMILE])
{

    char temp_matrix_c[ROW][COLUMN] = {
        {' ', SYMBOL_FOR_LETTERS, SYMBOL_FOR_LETTERS, SYMBOL_FOR_LETTERS, SYMBOL_FOR_LETTERS, SYMBOL_FOR_LETTERS, ' '},
        {SYMBOL_FOR_LETTERS, ' ', ' ', ' ', ' ', ' ', SYMBOL_FOR_LETTERS},
        {SYMBOL_FOR_LETTERS, ' ', ' ', ' ', ' ', ' ', ' '},
        {SYMBOL_FOR_LETTERS, ' ', ' ', ' ', ' ', ' ', ' '},
        {SYMBOL_FOR_LETTERS, ' ', ' ', ' ', ' ', ' ', ' '},
        {SYMBOL_FOR_LETTERS, ' ', ' ', ' ', ' ', ' ', SYMBOL_FOR_LETTERS},
        {' ', SYMBOL_FOR_LETTERS, SYMBOL_FOR_LETTERS, SYMBOL_FOR_LETTERS, SYMBOL_FOR_LETTERS, SYMBOL_FOR_LETTERS, ' '},
    };

    for (int i = 0; i < ROW; i++)
    {
        for (int j = 0; j < COLUMN; j++)
        {
            matrix_c[i][j] = temp_matrix_c[i][j];
        }
    }

    char temp_matrix_d[ROW][COLUMN] = {
        {' ', ' ', SYMBOL_FOR_LETTERS, SYMBOL_FOR_LETTERS, SYMBOL_FOR_LETTERS, ' ', ' '},
        {' ', SYMBOL_FOR_LETTERS, ' ', ' ', ' ', SYMBOL_FOR_LETTERS, ' '},
        {' ', SYMBOL_FOR_LETTERS, ' ', ' ', ' ', SYMBOL_FOR_LETTERS, ' '},
        {' ', SYMBOL_FOR_LETTERS, ' ', ' ', ' ', SYMBOL_FOR_LETTERS, ' '},
        {' ', SYMBOL_FOR_LETTERS, ' ', ' ', ' ', SYMBOL_FOR_LETTERS, ' '},
        {SYMBOL_FOR_LETTERS, SYMBOL_FOR_LETTERS, SYMBOL_FOR_LETTERS, SYMBOL_FOR_LETTERS, SYMBOL_FOR_LETTERS, SYMBOL_FOR_LETTERS, SYMBOL_FOR_LETTERS},
        {SYMBOL_FOR_LETTERS, ' ', ' ', ' ', ' ', ' ', SYMBOL_FOR_LETTERS},
    };

    for (int i = 0; i < ROW; i++)
    {
        for (int j = 0; j < COLUMN; j++)
        {
            matrix_d[i][j] = temp_matrix_d[i][j];
        }
    }

    char temp_matrix_n[ROW][COLUMN] = {
        {SYMBOL_FOR_LETTERS, ' ', ' ', ' ', ' ', ' ', SYMBOL_FOR_LETTERS},
        {SYMBOL_FOR_LETTERS, ' ', ' ', ' ', ' ', ' ', SYMBOL_FOR_LETTERS},
        {SYMBOL_FOR_LETTERS, ' ', ' ', ' ', ' ', ' ', SYMBOL_FOR_LETTERS},
        {SYMBOL_FOR_LETTERS, SYMBOL_FOR_LETTERS, SYMBOL_FOR_LETTERS, SYMBOL_FOR_LETTERS, SYMBOL_FOR_LETTERS, SYMBOL_FOR_LETTERS, SYMBOL_FOR_LETTERS},
        {SYMBOL_FOR_LETTERS, ' ', ' ', ' ', ' ', ' ', SYMBOL_FOR_LETTERS},
        {SYMBOL_FOR_LETTERS, ' ', ' ', ' ', ' ', ' ', SYMBOL_FOR_LETTERS},
        {SYMBOL_FOR_LETTERS, ' ', ' ', ' ', ' ', ' ', SYMBOL_FOR_LETTERS},
    };

    for (int i = 0; i < ROW; i++)
    {
        for (int j = 0; j < COLUMN; j++)
        {
            matrix_n[i][j] = temp_matrix_n[i][j];
        }
    }

    char temp_matrix_e[ROW][COLUMN] = {
        {SYMBOL_FOR_LETTERS, SYMBOL_FOR_LETTERS, SYMBOL_FOR_LETTERS, SYMBOL_FOR_LETTERS, SYMBOL_FOR_LETTERS, SYMBOL_FOR_LETTERS, SYMBOL_FOR_LETTERS},
        {SYMBOL_FOR_LETTERS, ' ', ' ', ' ', ' ', ' ', ' '},
        {SYMBOL_FOR_LETTERS, ' ', ' ', ' ', ' ', ' ', ' '},
        {SYMBOL_FOR_LETTERS, SYMBOL_FOR_LETTERS, SYMBOL_FOR_LETTERS, SYMBOL_FOR_LETTERS, SYMBOL_FOR_LETTERS, SYMBOL_FOR_LETTERS, ' '},
        {SYMBOL_FOR_LETTERS, ' ', ' ', ' ', ' ', ' ', ' '},
        {SYMBOL_FOR_LETTERS, ' ', ' ', ' ', ' ', ' ', ' '},
        {SYMBOL_FOR_LETTERS, SYMBOL_FOR_LETTERS, SYMBOL_FOR_LETTERS, SYMBOL_FOR_LETTERS, SYMBOL_FOR_LETTERS, SYMBOL_FOR_LETTERS, SYMBOL_FOR_LETTERS},
    };

    for (int i = 0; i < ROW; i++)
    {
        for (int j = 0; j < COLUMN; j++)
        {
            matrix_e[i][j] = temp_matrix_e[i][j];
        }
    }

    char temp_matrix_m[ROW][COLUMN] = {
        {SYMBOL_FOR_LETTERS, ' ', ' ', ' ', ' ', ' ', SYMBOL_FOR_LETTERS},
        {SYMBOL_FOR_LETTERS, SYMBOL_FOR_LETTERS, ' ', ' ', ' ', SYMBOL_FOR_LETTERS, SYMBOL_FOR_LETTERS},
        {SYMBOL_FOR_LETTERS, ' ', SYMBOL_FOR_LETTERS, ' ', SYMBOL_FOR_LETTERS, ' ', SYMBOL_FOR_LETTERS},
        {SYMBOL_FOR_LETTERS, ' ', ' ', SYMBOL_FOR_LETTERS, ' ', ' ', SYMBOL_FOR_LETTERS},
        {SYMBOL_FOR_LETTERS, ' ', ' ', ' ', ' ', ' ', SYMBOL_FOR_LETTERS},
        {SYMBOL_FOR_LETTERS, ' ', ' ', ' ', ' ', ' ', SYMBOL_FOR_LETTERS},
        {SYMBOL_FOR_LETTERS, ' ', ' ', ' ', ' ', ' ', SYMBOL_FOR_LETTERS},
    };

    for (int i = 0; i < ROW; i++)
    {
        for (int j = 0; j < COLUMN; j++)
        {
            matrix_m[i][j] = temp_matrix_m[i][j];
        }
    }

    char temp_matrix_r[ROW][COLUMN] = {
        {SYMBOL_FOR_LETTERS, SYMBOL_FOR_LETTERS, SYMBOL_FOR_LETTERS, SYMBOL_FOR_LETTERS, SYMBOL_FOR_LETTERS, SYMBOL_FOR_LETTERS, ' '},
        {SYMBOL_FOR_LETTERS, ' ', ' ', ' ', ' ', ' ', SYMBOL_FOR_LETTERS},
        {SYMBOL_FOR_LETTERS, ' ', ' ', ' ', ' ', ' ', SYMBOL_FOR_LETTERS},
        {SYMBOL_FOR_LETTERS, SYMBOL_FOR_LETTERS, SYMBOL_FOR_LETTERS, SYMBOL_FOR_LETTERS, SYMBOL_FOR_LETTERS, SYMBOL_FOR_LETTERS, ' '},
        {SYMBOL_FOR_LETTERS, ' ', ' ', ' ', ' ', ' ', ' '},
        {SYMBOL_FOR_LETTERS, ' ', ' ', ' ', ' ', ' ', ' '},
        {SYMBOL_FOR_LETTERS, ' ', ' ', ' ', ' ', ' ', ' '},
    };

    for (int i = 0; i < ROW; i++)
    {
        for (int j = 0; j < COLUMN; j++)
        {
            matrix_r[i][j] = temp_matrix_r[i][j];
        }
    }

    char temp_matrix_o[ROW][COLUMN] = {
        {' ', SYMBOL_FOR_LETTERS, SYMBOL_FOR_LETTERS, SYMBOL_FOR_LETTERS, SYMBOL_FOR_LETTERS, SYMBOL_FOR_LETTERS, ' '},
        {SYMBOL_FOR_LETTERS, ' ', ' ', ' ', ' ', ' ', SYMBOL_FOR_LETTERS},
        {SYMBOL_FOR_LETTERS, ' ', ' ', ' ', ' ', ' ', SYMBOL_FOR_LETTERS},
        {SYMBOL_FOR_LETTERS, ' ', ' ', ' ', ' ', ' ', SYMBOL_FOR_LETTERS},
        {SYMBOL_FOR_LETTERS, ' ', ' ', ' ', ' ', ' ', SYMBOL_FOR_LETTERS},
        {SYMBOL_FOR_LETTERS, ' ', ' ', ' ', ' ', ' ', SYMBOL_FOR_LETTERS},
        {' ', SYMBOL_FOR_LETTERS, SYMBOL_FOR_LETTERS, SYMBOL_FOR_LETTERS, SYMBOL_FOR_LETTERS, SYMBOL_FOR_LETTERS, ' '},
    };

    for (int i = 0; i < ROW; i++)
    {
        for (int j = 0; j < COLUMN; j++)
        {
            matrix_o[i][j] = temp_matrix_o[i][j];
        }
    }

    char temp_matrix_zh[ROW][COLUMN] = {
        {SYMBOL_FOR_LETTERS, ' ', ' ', SYMBOL_FOR_LETTERS, ' ', ' ', SYMBOL_FOR_LETTERS},
        {SYMBOL_FOR_LETTERS, ' ', ' ', SYMBOL_FOR_LETTERS, ' ', ' ', SYMBOL_FOR_LETTERS},
        {SYMBOL_FOR_LETTERS, SYMBOL_FOR_LETTERS, ' ', SYMBOL_FOR_LETTERS, ' ', SYMBOL_FOR_LETTERS, SYMBOL_FOR_LETTERS},
        {' ', SYMBOL_FOR_LETTERS, SYMBOL_FOR_LETTERS, SYMBOL_FOR_LETTERS, SYMBOL_FOR_LETTERS, SYMBOL_FOR_LETTERS, ' '},
        {SYMBOL_FOR_LETTERS, SYMBOL_FOR_LETTERS, ' ', SYMBOL_FOR_LETTERS, ' ', SYMBOL_FOR_LETTERS, SYMBOL_FOR_LETTERS},
        {SYMBOL_FOR_LETTERS, ' ', ' ', SYMBOL_FOR_LETTERS, ' ', ' ', SYMBOL_FOR_LETTERS},
        {SYMBOL_FOR_LETTERS, ' ', ' ', SYMBOL_FOR_LETTERS, ' ', ' ', SYMBOL_FOR_LETTERS},
    };

    for (int i = 0; i < ROW; i++)
    {
        for (int j = 0; j < COLUMN; j++)
        {
            matrix_zh[i][j] = temp_matrix_zh[i][j];
        }
    }

    char temp_matrix_i[ROW][COLUMN] = {
        {SYMBOL_FOR_LETTERS, ' ', ' ', ' ', ' ', ' ', SYMBOL_FOR_LETTERS},
        {SYMBOL_FOR_LETTERS, ' ', ' ', ' ', ' ', SYMBOL_FOR_LETTERS, SYMBOL_FOR_LETTERS},
        {SYMBOL_FOR_LETTERS, ' ', ' ', ' ', SYMBOL_FOR_LETTERS, ' ', SYMBOL_FOR_LETTERS},
        {SYMBOL_FOR_LETTERS, ' ', ' ', SYMBOL_FOR_LETTERS, ' ', ' ', SYMBOL_FOR_LETTERS},
        {SYMBOL_FOR_LETTERS, ' ', SYMBOL_FOR_LETTERS, ' ', ' ', ' ', SYMBOL_FOR_LETTERS},
        {SYMBOL_FOR_LETTERS, SYMBOL_FOR_LETTERS, ' ', ' ', ' ', ' ', SYMBOL_FOR_LETTERS},
        {SYMBOL_FOR_LETTERS, ' ', ' ', ' ', ' ', ' ', SYMBOL_FOR_LETTERS},
    };

    for (int i = 0; i < ROW; i++)
    {
        for (int j = 0; j < COLUMN; j++)
        {
            matrix_i[i][j] = temp_matrix_i[i][j];
        }
    }

    char temp_matrix_ya[ROW][COLUMN] = {
        {' ', SYMBOL_FOR_LETTERS, SYMBOL_FOR_LETTERS, SYMBOL_FOR_LETTERS, SYMBOL_FOR_LETTERS, SYMBOL_FOR_LETTERS, SYMBOL_FOR_LETTERS},
        {SYMBOL_FOR_LETTERS, ' ', ' ', ' ', ' ', ' ', SYMBOL_FOR_LETTERS},
        {SYMBOL_FOR_LETTERS, ' ', ' ', ' ', ' ', ' ', SYMBOL_FOR_LETTERS},
        {' ', SYMBOL_FOR_LETTERS, SYMBOL_FOR_LETTERS, SYMBOL_FOR_LETTERS, SYMBOL_FOR_LETTERS, SYMBOL_FOR_LETTERS, SYMBOL_FOR_LETTERS},
        {' ', ' ', ' ', ' ', SYMBOL_FOR_LETTERS, SYMBOL_FOR_LETTERS, SYMBOL_FOR_LETTERS},
        {' ', ' ', ' ', SYMBOL_FOR_LETTERS, ' ', ' ', SYMBOL_FOR_LETTERS},
        {SYMBOL_FOR_LETTERS, SYMBOL_FOR_LETTERS, SYMBOL_FOR_LETTERS, ' ', ' ', ' ', SYMBOL_FOR_LETTERS},
    };

    for (int i = 0; i < ROW; i++)
    {
        for (int j = 0; j < COLUMN; j++)
        {
            matrix_ya[i][j] = temp_matrix_ya[i][j];
        }
    }

    char temp_matrix_w[ROW][COLUMN] = {
        {' ', SYMBOL_FOR_LETTERS, ' ', SYMBOL_FOR_LETTERS, ' ', SYMBOL_FOR_LETTERS, ' '},
        {' ', SYMBOL_FOR_LETTERS, ' ', SYMBOL_FOR_LETTERS, ' ', SYMBOL_FOR_LETTERS, ' '},
        {' ', SYMBOL_FOR_LETTERS, ' ', SYMBOL_FOR_LETTERS, ' ', SYMBOL_FOR_LETTERS, ' '},
        {' ', SYMBOL_FOR_LETTERS, ' ', SYMBOL_FOR_LETTERS, ' ', SYMBOL_FOR_LETTERS, ' '},
        {' ', SYMBOL_FOR_LETTERS, ' ', SYMBOL_FOR_LETTERS, ' ', SYMBOL_FOR_LETTERS, ' '},
        {' ', ' ', ' ', ' ', ' ', ' ', ' '},
        {' ', SYMBOL_FOR_LETTERS, ' ', SYMBOL_FOR_LETTERS, ' ', SYMBOL_FOR_LETTERS, ' '},
    };

    for (int i = 0; i < ROW; i++)
    {
        for (int j = 0; j < COLUMN; j++)
        {
            matrix_w[i][j] = temp_matrix_w[i][j];
        }
    }

    char temp_matrix_smile[ROW_SMILE][COLUMN_SMILE] = {
        {' ', ' ', ' ', SYMBOL_FOR_LETTERS, SYMBOL_FOR_LETTERS, SYMBOL_FOR_LETTERS, SYMBOL_FOR_LETTERS, SYMBOL_FOR_LETTERS, SYMBOL_FOR_LETTERS, SYMBOL_FOR_LETTERS, SYMBOL_FOR_LETTERS, SYMBOL_FOR_LETTERS, SYMBOL_FOR_LETTERS, ' ', ' ', ' '},
        {' ', ' ', SYMBOL_FOR_LETTERS, SYMBOL_FOR_LETTERS, SYMBOL_FOR_LETTERS, SYMBOL_FOR_LETTERS, SYMBOL_FOR_LETTERS, SYMBOL_FOR_LETTERS, SYMBOL_FOR_LETTERS, SYMBOL_FOR_LETTERS, SYMBOL_FOR_LETTERS, SYMBOL_FOR_LETTERS, SYMBOL_FOR_LETTERS, SYMBOL_FOR_LETTERS, ' ', ' '},
        {' ', SYMBOL_FOR_LETTERS, SYMBOL_FOR_LETTERS, SYMBOL_FOR_LETTERS, SYMBOL_FOR_LETTERS, SYMBOL_FOR_LETTERS, SYMBOL_FOR_LETTERS, SYMBOL_FOR_LETTERS, SYMBOL_FOR_LETTERS, SYMBOL_FOR_LETTERS, SYMBOL_FOR_LETTERS, SYMBOL_FOR_LETTERS, SYMBOL_FOR_LETTERS, SYMBOL_FOR_LETTERS, SYMBOL_FOR_LETTERS, ' '},
        {SYMBOL_FOR_LETTERS, SYMBOL_FOR_LETTERS, SYMBOL_FOR_LETTERS, ' ', ' ', SYMBOL_FOR_LETTERS, SYMBOL_FOR_LETTERS, SYMBOL_FOR_LETTERS, SYMBOL_FOR_LETTERS, SYMBOL_FOR_LETTERS, SYMBOL_FOR_LETTERS, ' ', ' ', SYMBOL_FOR_LETTERS, SYMBOL_FOR_LETTERS, SYMBOL_FOR_LETTERS},
        {SYMBOL_FOR_LETTERS, SYMBOL_FOR_LETTERS, SYMBOL_FOR_LETTERS, ' ', ' ', SYMBOL_FOR_LETTERS, SYMBOL_FOR_LETTERS, SYMBOL_FOR_LETTERS, SYMBOL_FOR_LETTERS, SYMBOL_FOR_LETTERS, SYMBOL_FOR_LETTERS, ' ', ' ', SYMBOL_FOR_LETTERS, SYMBOL_FOR_LETTERS, SYMBOL_FOR_LETTERS},
        {SYMBOL_FOR_LETTERS, SYMBOL_FOR_LETTERS, SYMBOL_FOR_LETTERS, SYMBOL_FOR_LETTERS, SYMBOL_FOR_LETTERS, SYMBOL_FOR_LETTERS, SYMBOL_FOR_LETTERS, SYMBOL_FOR_LETTERS, SYMBOL_FOR_LETTERS, SYMBOL_FOR_LETTERS, SYMBOL_FOR_LETTERS, SYMBOL_FOR_LETTERS, SYMBOL_FOR_LETTERS, SYMBOL_FOR_LETTERS, SYMBOL_FOR_LETTERS, SYMBOL_FOR_LETTERS},
        {SYMBOL_FOR_LETTERS, SYMBOL_FOR_LETTERS, SYMBOL_FOR_LETTERS, ' ', SYMBOL_FOR_LETTERS, SYMBOL_FOR_LETTERS, SYMBOL_FOR_LETTERS, SYMBOL_FOR_LETTERS, SYMBOL_FOR_LETTERS, SYMBOL_FOR_LETTERS, SYMBOL_FOR_LETTERS, SYMBOL_FOR_LETTERS, ' ', SYMBOL_FOR_LETTERS, SYMBOL_FOR_LETTERS, SYMBOL_FOR_LETTERS},
        {SYMBOL_FOR_LETTERS, SYMBOL_FOR_LETTERS, SYMBOL_FOR_LETTERS, ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', SYMBOL_FOR_LETTERS, SYMBOL_FOR_LETTERS, SYMBOL_FOR_LETTERS},
        {SYMBOL_FOR_LETTERS, SYMBOL_FOR_LETTERS, SYMBOL_FOR_LETTERS, SYMBOL_FOR_LETTERS, ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', SYMBOL_FOR_LETTERS, SYMBOL_FOR_LETTERS, SYMBOL_FOR_LETTERS, SYMBOL_FOR_LETTERS},
        {' ', SYMBOL_FOR_LETTERS, SYMBOL_FOR_LETTERS, SYMBOL_FOR_LETTERS, SYMBOL_FOR_LETTERS, SYMBOL_FOR_LETTERS, SYMBOL_FOR_LETTERS, SYMBOL_FOR_LETTERS, SYMBOL_FOR_LETTERS, SYMBOL_FOR_LETTERS, SYMBOL_FOR_LETTERS, SYMBOL_FOR_LETTERS, SYMBOL_FOR_LETTERS, SYMBOL_FOR_LETTERS, SYMBOL_FOR_LETTERS, ' '},
        {' ', ' ', SYMBOL_FOR_LETTERS, SYMBOL_FOR_LETTERS, SYMBOL_FOR_LETTERS, SYMBOL_FOR_LETTERS, SYMBOL_FOR_LETTERS, SYMBOL_FOR_LETTERS, SYMBOL_FOR_LETTERS, SYMBOL_FOR_LETTERS, SYMBOL_FOR_LETTERS, SYMBOL_FOR_LETTERS, SYMBOL_FOR_LETTERS, SYMBOL_FOR_LETTERS, ' ', ' '},
        {' ', ' ', ' ', SYMBOL_FOR_LETTERS, SYMBOL_FOR_LETTERS, SYMBOL_FOR_LETTERS, SYMBOL_FOR_LETTERS, SYMBOL_FOR_LETTERS, SYMBOL_FOR_LETTERS, SYMBOL_FOR_LETTERS, SYMBOL_FOR_LETTERS, SYMBOL_FOR_LETTERS, SYMBOL_FOR_LETTERS, ' ', ' ', ' '},
    };

    for (int i = 0; i < ROW_SMILE; i++)
    {
        for (int j = 0; j < COLUMN_SMILE; j++)
        {
            matrix_smile[i][j] = temp_matrix_smile[i][j];
        }
    }
}
