#include "renderScreenGame.h"

/**
 * Отрисовывает игровое поле
 *
 * Формирует в буфере изображение игрового поля с ракетками, мячом и границами.
 * Выводит текущий счет и инструкции по управлению.
 *
 * @param centerRocketOne Позиция левой ракетки
 * @param centerRocketTwo Позиция правой ракетки
 * @param ballX Горизонтальная позиция мяча
 * @param ballY Вертикальная позиция мяча
 * @param scorePlayerOne Счет первого игрока
 * @param scorePlayerTwo Счет второго игрока
 *
 * @see printTable
 */
void printGameField(int centerRocketOne, int centerRocketTwo, int ballX, int ballY,
                    int scorePlayerOne, int scorePlayerTwo)
{
    // Отрисовка таблицы счета
    printTable(scorePlayerOne, scorePlayerTwo);

    // Отрисовка игрового поля
    for (int y = 1; y <= HEIGHT_FIELD; y++)
    {
        for (int x = 1; x <= WIDTH_FIELD; x++)
        {
            if (y == ballY && x == ballX)
            {
                setChar(x, y, 'O', FOREGROUND_RED | FOREGROUND_INTENSITY);
            }
            else if (x == 3 && (y == centerRocketOne - 1 || y == centerRocketOne || y == centerRocketOne + 1))
            {
                setChar(x, y, '#', FOREGROUND_BLUE | FOREGROUND_INTENSITY);
            }
            else if (x == WIDTH_FIELD - 2 && (y == centerRocketTwo - 1 || y == centerRocketTwo || y == centerRocketTwo + 1))
            {
                setChar(x, y, '#', FOREGROUND_GREEN | FOREGROUND_INTENSITY);
            }
            else if (y == 1 || y == HEIGHT_FIELD)
            {
                setChar(x, y, '-', FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
            }
            else if ((x == 1 || x == WIDTH_FIELD || x == (WIDTH_FIELD - 2) / 2) && y != HEIGHT_FIELD)
            {
                setChar(x, y, '|', FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
            }
        }
    }

    // Инструкции
    drawText(10, HEIGHT_FIELD + 2, "Player One: A/Z. Player Two: K/M. ESC: Exit", FOREGROUND_INTENSITY);
}

/**
 * Отрисовывает таблицу счета
 *
 * Выводит в верхней части экрана текущий счет игроков.
 *
 * @param scorePlayerOne Счет первого игрока
 * @param scorePlayerTwo Счет второго игрока
 */
void printTable(int scorePlayerOne, int scorePlayerTwo)
{
    char scoreText[50];
    sprintf(scoreText, "| Player 1: %02d | Player 2: %02d |", scorePlayerOne, scorePlayerTwo);
    drawText(25, 0, scoreText, FOREGROUND_INTENSITY);
}

/**
 * Показывает экран победы
 *
 * Отображает сообщение о победителе и итоговый счет.
 * Ожидает нажатия любой клавиши для возврата в меню.
 *
 * @param scorePlayerOne Счет первого игрока
 * @param scorePlayerTwo Счет второго игрока
 */
void printWinPlayer(int scorePlayerOne, int scorePlayerTwo)
{
    clearBuffer();

    char winText[60];
    if (scorePlayerOne > scorePlayerTwo)
    {
        sprintf(winText, "PLAYER 1 WINS! Score: %02d : %02d", scorePlayerOne, scorePlayerTwo);
    }
    else
    {
        sprintf(winText, "PLAYER 2 WINS! Score: %02d : %02d", scorePlayerOne, scorePlayerTwo);
    }

    drawText(15, CONSOLE_HEIGHT / 2, winText, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_INTENSITY);
    drawText(25, CONSOLE_HEIGHT / 2 + 2, "Press any key to return to menu", FOREGROUND_INTENSITY);

    renderBuffer();
}
