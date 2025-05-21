#include "runGame.h"

/**
 * Основной игровой цикл
 *
 * Управляет процессом игры: обработкой ввода, обновлением состояния, отрисовкой.
 * Содержит логику движения мяча, подсчета очков и определения победителя.
 *
 * @param settings Настройки игры (скорость, лимит очков)
 *
 * @see printGameField, moveRocket, ballHitRocket, bounceWall
 */
void runGame(GameSettings settings)
{
    int ballX = WIDTH_FIELD / 2 - 1, ballY = HEIGHT_FIELD / 2 + 1;
    int directionX = 1, directionY = 1;
    int rocketOneY = HEIGHT_FIELD / 2, rocketTwoY = HEIGHT_FIELD / 2;
    int scorePlayerOne = 0, scorePlayerTwo = 0;
    int wallLeft = 3, wallRight = WIDTH_FIELD - 2;
    int wallTop = 2, wallBottom = HEIGHT_FIELD - 1;

    while (true)
    {
        clearBuffer();

        // Обработка ввода (с проверкой на ESC)
        if (_kbhit())
        {
            int key = _getch();
            if (key == ESC_KEY)
            {
                return; // Выход из игры в меню
            }
            rocketOneY = moveRocket(1, rocketOneY, key);
            rocketTwoY = moveRocket(2, rocketTwoY, key);
        }

        // Обновление позиции мяча
        ballX += directionX;
        ballY += directionY;

        // Проверка столкновений с ракетками
        if (directionX < 0 && ballX == wallLeft)
        {
            directionX *= -1;
            if (!ballHitRocket(ballY, rocketOneY))
            {
                scorePlayerTwo++;
                ballX = WIDTH_FIELD / 2 - 1;
                ballY = HEIGHT_FIELD / 2 + 1;
                rocketOneY = rocketTwoY = HEIGHT_FIELD / 2;
                continue;
            }
        }
        else if (directionX > 0 && ballX == wallRight)
        {
            directionX *= -1;
            if (!ballHitRocket(ballY, rocketTwoY))
            {
                scorePlayerOne++;
                ballX = WIDTH_FIELD / 2 - 1;
                ballY = HEIGHT_FIELD / 2 + 1;
                rocketOneY = rocketTwoY = HEIGHT_FIELD / 2;
                continue;
            }
        }

        // Проверка столкновений со стенами
        directionY = bounceWall(directionY, ballY);

        // Отрисовка игры
        printGameField(rocketOneY, rocketTwoY, ballX, ballY, scorePlayerOne, scorePlayerTwo);
        renderBuffer();

        // Проверка победы
        if (scorePlayerOne == settings.winScore || scorePlayerTwo == settings.winScore)
        {
            break;
        }

        Sleep(settings.timeLag);
    }

    // Вывод сообщения о победе
    printWinPlayer(scorePlayerOne, scorePlayerTwo);

    // Ожидание перед возвратом в меню
    while (!_kbhit())
    {
        Sleep(100);
    }
    _getch(); // Считываем нажатую клавишу
}
