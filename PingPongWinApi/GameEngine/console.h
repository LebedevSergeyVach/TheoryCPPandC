#ifndef CONSOLE_H
#define CONSOLE_H

#include "game.h"

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
void initConsole();

#endif
