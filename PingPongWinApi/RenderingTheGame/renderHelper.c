#include "renderHelper.h"

/**
 * Очищает буфер экрана
 *
 * Заполняет весь буфер экрана пробелами с стандартными атрибутами цвета.
 * Подготавливает экран для нового кадра отрисовки.
 *
 * @property consoleBuffer - двумерный массив CHAR_INFO для хранения экрана
 */
void clearBuffer()
{
    for (int y = 0; y < CONSOLE_HEIGHT; y++)
    {
        for (int x = 0; x < CONSOLE_WIDTH; x++)
        {
            consoleBuffer[y][x].Char.AsciiChar = ' ';
            consoleBuffer[y][x].Attributes = FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_RED;
        }
    }
}

/**
 * Выводит содержимое буфера на экран
 *
 * Осуществляет вывод подготовленного буфера на физический экран консоли.
 * Использует двойную буферизацию для устранения мерцания.
 *
 * @see WriteConsoleOutput
 */
void renderBuffer()
{
    COORD bufferSize = {CONSOLE_WIDTH, CONSOLE_HEIGHT};
    COORD bufferCoord = {0, 0};
    SMALL_RECT writeRegion = {0, 0, CONSOLE_WIDTH - 1, CONSOLE_HEIGHT - 1};

    WriteConsoleOutput(hConsoleOutput, (CHAR_INFO *)consoleBuffer, bufferSize, bufferCoord, &writeRegion);
}

/**
 * Устанавливает символ в буфер экрана
 *
 * Записывает указанный символ с заданными атрибутами цвета в указанную позицию буфера.
 * Проверяет границы буфера для предотвращения ошибок доступа.
 *
 * @param x Горизонтальная координата (0-based)
 * @param y Вертикальная координата (0-based)
 * @param c Символ для отображения
 * @param color Атрибуты цвета (FOREGROUND_* | BACKGROUND_*)
 */
void setChar(int x, int y, char c, WORD color)
{
    if (x >= 0 && x < CONSOLE_WIDTH && y >= 0 && y < CONSOLE_HEIGHT)
    {
        consoleBuffer[y][x].Char.AsciiChar = c;
        consoleBuffer[y][x].Attributes = color;
    }
}

/**
 * Рисует текст в буфере экрана
 *
 * Последовательно записывает строку символов в буфер начиная с указанной позиции.
 *
 * @param x Начальная горизонтальная координата
 * @param y Начальная вертикальная координата
 * @param text Строка для отображения
 * @param color Атрибуты цвета текста
 *
 * @see setChar
 */
void drawText(int x, int y, const char *text, WORD color)
{
    for (int i = 0; text[i] != '\0'; i++)
    {
        setChar(x + i, y, text[i], color);
    }
}
