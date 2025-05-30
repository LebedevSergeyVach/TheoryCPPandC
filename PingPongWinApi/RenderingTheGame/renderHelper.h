#ifndef RENDER_HELPER_H
#define RENDER_HELPER_H

#include "renderGame.h"

/**
 * Очищает буфер экрана
 *
 * Заполняет весь буфер экрана пробелами с стандартными атрибутами цвета.
 * Подготавливает экран для нового кадра отрисовки.
 *
 * @property consoleBuffer - двумерный массив CHAR_INFO для хранения экрана
 */
void clearBuffer();

/**
 * Выводит содержимое буфера на экран
 *
 * Осуществляет вывод подготовленного буфера на физический экран консоли.
 * Использует двойную буферизацию для устранения мерцания.
 *
 * @see WriteConsoleOutput
 */
void renderBuffer();

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
void setChar(int x, int y, char c, WORD color);

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
void drawText(int x, int y, const char *text, WORD color);

#endif
