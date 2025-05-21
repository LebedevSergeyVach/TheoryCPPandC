#include "console.h"

/**
 * Инициализирует консоль для работы игры
 *
 * Настраивает размер консольного окна, буфер экрана и скрывает курсор.
 * Устанавливает стандартные параметры для корректного отображения игры.
 * Должна быть вызвана перед началом работы с консольными функциями.
 *
 * @property hConsoleOutput - хэндл консоли для вывода
 * @property cursorPosition - текущая позиция курсора
 *
 * @see SetConsoleWindowInfo, SetConsoleScreenBufferSize, SetConsoleCursorInfo
 */
void initConsole()
{
    hConsoleOutput = GetStdHandle(STD_OUTPUT_HANDLE);

    // Установка размера консоли
    SMALL_RECT windowSize = {0, 0, CONSOLE_WIDTH - 1, CONSOLE_HEIGHT - 1};
    SetConsoleWindowInfo(hConsoleOutput, TRUE, &windowSize);

    COORD bufferSize = {CONSOLE_WIDTH, CONSOLE_HEIGHT};
    SetConsoleScreenBufferSize(hConsoleOutput, bufferSize);

    // Скрытие курсора
    CONSOLE_CURSOR_INFO cursorInfo;
    cursorInfo.dwSize = 1;
    cursorInfo.bVisible = FALSE;
    SetConsoleCursorInfo(hConsoleOutput, &cursorInfo);
}
