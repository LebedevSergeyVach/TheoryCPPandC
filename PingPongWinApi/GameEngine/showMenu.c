#include "showMenu.h"

/**
 * Отображает главное меню игры
 *
 * Показывает интерактивное меню с настройками скорости игры и очков для победы.
 * Обрабатывает пользовательский ввод для навигации по меню.
 *
 * @return GameSettings Структура с выбранными настройками игры
 *
 * @property selectedSpeed Текущая выбранная скорость (1-3)
 * @property selectedWinScore Текущий выбранный лимит очков (1-3)
 * @property currentSelection Текущий выбранный пункт меню
 */
GameSettings showMenu()
{
    GameSettings settings = {DEFAULT_TIME_LAG, DEFAULT_WINSCORE};
    int selectedSpeed = 2;    // Средняя скорость по умолчанию
    int selectedWinScore = 2; // 10 очков по умолчанию
    int currentSelection = 0; // 0 - скорость, 1 - очки, 2 - старт

    while (true)
    {
        clearBuffer();

        // Заголовок
        drawText(30, 5, "     PING PONG GAME     ", FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_INTENSITY);

        // Выбор скорости
        drawText(25, 10, "Game Speed:", FOREGROUND_INTENSITY);
        drawText(25, 11, "1. Slow", currentSelection == 0 && selectedSpeed == 1 ? FOREGROUND_GREEN | FOREGROUND_INTENSITY : FOREGROUND_INTENSITY);
        drawText(25, 12, "2. Medium", currentSelection == 0 && selectedSpeed == 2 ? FOREGROUND_GREEN | FOREGROUND_INTENSITY : FOREGROUND_INTENSITY);
        drawText(25, 13, "3. Fast", currentSelection == 0 && selectedSpeed == 3 ? FOREGROUND_GREEN | FOREGROUND_INTENSITY : FOREGROUND_INTENSITY);

        // Выбор очков для победы
        drawText(50, 10, "Points to Win:", FOREGROUND_INTENSITY);
        drawText(50, 11, "1. 5 points", currentSelection == 1 && selectedWinScore == 1 ? FOREGROUND_GREEN | FOREGROUND_INTENSITY : FOREGROUND_INTENSITY);
        drawText(50, 12, "2. 10 points", currentSelection == 1 && selectedWinScore == 2 ? FOREGROUND_GREEN | FOREGROUND_INTENSITY : FOREGROUND_INTENSITY);
        drawText(50, 13, "3. 15 points", currentSelection == 1 && selectedWinScore == 3 ? FOREGROUND_GREEN | FOREGROUND_INTENSITY : FOREGROUND_INTENSITY);

        // Кнопка старта
        drawText(38, 18, "START GAME", currentSelection == 2 ? FOREGROUND_GREEN | FOREGROUND_INTENSITY : FOREGROUND_INTENSITY);

        // Инструкция
        drawText(25, 22, "Use ARROW KEYS to navigate, ENTER to select, ESC to exit", FOREGROUND_INTENSITY);

        renderBuffer();

        // Обработка ввода
        if (_kbhit())
        {
            int key = _getch();

            // Обработка стрелок
            if (key == 0 || key == 0xE0)
            {
                key = _getch(); // Получаем расширенный код

                switch (key)
                {
                case 72: // Вверх
                    if (currentSelection > 0)
                        currentSelection--;
                    break;
                case 80: // Вниз
                    if (currentSelection < 2)
                        currentSelection++;
                    break;
                case 75: // Влево
                    if (currentSelection == 0 && selectedSpeed > 1)
                        selectedSpeed--;
                    if (currentSelection == 1 && selectedWinScore > 1)
                        selectedWinScore--;
                    break;
                case 77: // Вправо
                    if (currentSelection == 0 && selectedSpeed < 3)
                        selectedSpeed++;
                    if (currentSelection == 1 && selectedWinScore < 3)
                        selectedWinScore++;
                    break;
                }
            }
            // Обработка Enter
            else if (key == 13)
            {
                if (currentSelection == 2)
                {
                    // Устанавливаем настройки игры
                    switch (selectedSpeed)
                    {
                    case 1:
                        settings.timeLag = 200;
                        break; // Медленно
                    case 2:
                        settings.timeLag = 150;
                        break; // Средне
                    case 3:
                        settings.timeLag = 100;
                        break; // Быстро
                    }

                    switch (selectedWinScore)
                    {
                    case 1:
                        settings.winScore = 5;
                        break;
                    case 2:
                        settings.winScore = 10;
                        break;
                    case 3:
                        settings.winScore = 15;
                        break;
                    }

                    return settings;
                }
            }
            // Обработка ESC
            else if (key == ESC_KEY)
            {
                exit(0);
            }
        }

        Sleep(50);
    }
}
